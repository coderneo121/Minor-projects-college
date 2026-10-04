const express=require("express");
const {Pool}=require("pg");
const path=require("path");
const app=express();
const PORT=process.env.PORT||10000;
const pool=new Pool({connectionString:process.env.DATABASE_URL,ssl:process.env.DATABASE_URL?{rejectUnauthorized:false}:false});
app.use(express.json());
app.use(express.static(path.join(__dirname,"public")));

const schema=`CREATE TABLE IF NOT EXISTS students(
 roll INTEGER PRIMARY KEY,
 name VARCHAR(100) NOT NULL,
 marks NUMERIC(5,2) NOT NULL CHECK(marks>=0 AND marks<=100),
 income NUMERIC(12,2) NOT NULL CHECK(income>=0),
 eligible BOOLEAN NOT NULL,
 created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)`;

async function init(){await pool.query(schema);console.log("PostgreSQL database ready");}
function eligible(m,i){return Number(m)>=75&&Number(i)<=300000}

app.get("/api/health",async(req,res)=>{try{await pool.query("SELECT 1");res.json({status:"online",database:"PostgreSQL"})}catch(e){res.status(500).json({status:"offline",error:e.message})}});

app.get("/api/students",async(req,res)=>{try{let r=await pool.query("SELECT roll,name,marks,income,eligible FROM students");let rows=r.rows;if(req.query.sort==="marks"){ // Bubble Sort for project demonstration
 for(let i=0;i<rows.length-1;i++)for(let j=0;j<rows.length-i-1;j++)if(Number(rows[j].marks)<Number(rows[j+1].marks)){let t=rows[j];rows[j]=rows[j+1];rows[j+1]=t}
}else rows.sort((a,b)=>a.roll-b.roll);res.json(rows)}catch(e){res.status(500).json({error:e.message})}});

app.post("/api/students",async(req,res)=>{let{roll,name,marks,income}=req.body;if(!Number.isInteger(Number(roll))||!String(name||"").trim()||marks===undefined||income===undefined)return res.status(400).json({error:"Please enter all student details."});if(Number(marks)<0||Number(marks)>100||Number(income)<0)return res.status(400).json({error:"Marks or income value is invalid."});try{let r=await pool.query("INSERT INTO students(roll,name,marks,income,eligible) VALUES($1,$2,$3,$4,$5) RETURNING roll,name,marks,income,eligible",[Number(roll),String(name).trim(),Number(marks),Number(income),eligible(marks,income)]);res.status(201).json(r.rows[0])}catch(e){res.status(400).json({error:e.code==="23505"?"Roll number already exists.":e.message})}});

app.delete("/api/students/:roll",async(req,res)=>{try{let r=await pool.query("DELETE FROM students WHERE roll=$1",[Number(req.params.roll)]);if(!r.rowCount)return res.status(404).json({error:"Student not found."});res.json({message:"Deleted"})}catch(e){res.status(500).json({error:e.message})}});
app.delete("/api/students",async(req,res)=>{try{await pool.query("DELETE FROM students");res.json({message:"All records deleted"})}catch(e){res.status(500).json({error:e.message})}});

// Linear Search: scans sorted records one by one.
app.get("/api/search/linear/:roll",async(req,res)=>{try{let r=await pool.query("SELECT roll,name,marks,income,eligible FROM students ORDER BY roll");let x=null;for(const s of r.rows){if(s.roll===Number(req.params.roll)){x=s;break}}if(!x)return res.status(404).json({error:"Student not found."});res.json(x)}catch(e){res.status(500).json({error:e.message})}});

// Binary Search: uses records sorted by roll number.
app.get("/api/search/binary/:roll",async(req,res)=>{try{let r=await pool.query("SELECT roll,name,marks,income,eligible FROM students ORDER BY roll");let a=r.rows,target=Number(req.params.roll),lo=0,hi=a.length-1,x=null;while(lo<=hi){let mid=Math.floor((lo+hi)/2);if(a[mid].roll===target){x=a[mid];break}if(a[mid].roll<target)lo=mid+1;else hi=mid-1}if(!x)return res.status(404).json({error:"Student not found."});res.json(x)}catch(e){res.status(500).json({error:e.message})}});

app.get("*",(req,res)=>res.sendFile(path.join(__dirname,"public","index.html")));
init().then(()=>app.listen(PORT,"0.0.0.0",()=>console.log("ScholarTrack running on port "+PORT))).catch(e=>{console.error(e);process.exit(1)});
let students = [];

const form = document.getElementById("studentForm");
const table = document.getElementById("studentTable");
const message = document.getElementById("message");

function checkEligibility(student) {
  return student.marks >= 75 && student.income <= 300000;
}

function showMessage(text, type = "success") {
  message.textContent = text;
  message.className = "message " + type;
  setTimeout(() => {
    message.textContent = "";
    message.className = "message";
  }, 2500);
}

form.addEventListener("submit", function (e) {
  e.preventDefault();

  const roll = Number(document.getElementById("roll").value);
  const name = document.getElementById("name").value.trim();
  const marks = Number(document.getElementById("marks").value);
  const income = Number(document.getElementById("income").value);

  if (!name || marks < 0 || marks > 100 || income < 0) {
    showMessage("Please enter valid student details.", "error");
    return;
  }

  if (students.some(s => s.roll === roll)) {
    showMessage("Roll number already exists.", "error");
    return;
  }

  students.push({
    roll,
    name,
    marks,
    income,
    eligible: checkEligibility({ marks, income })
  });

  form.reset();
  render();
  showMessage("Student added successfully.");
});

function render() {
  table.innerHTML = "";

  if (students.length === 0) {
    document.getElementById("emptyState").style.display = "block";
  } else {
    document.getElementById("emptyState").style.display = "none";
  }

  students.forEach((student) => {
    const row = document.createElement("tr");

    row.innerHTML = `
      <td>${student.roll}</td>
      <td><strong>${escapeHtml(student.name)}</strong></td>
      <td>${student.marks}</td>
      <td>₹${student.income.toLocaleString("en-IN")}</td>
      <td>
        <span class="badge ${student.eligible ? "yes" : "no"}">
          ${student.eligible ? "Eligible" : "Not Eligible"}
        </span>
      </td>
      <td>
        <button class="danger" onclick="deleteStudent(${student.roll})">Delete</button>
      </td>
    `;

    table.appendChild(row);
  });

  updateStats();
  renderEligible();
  renderTopStudent();
}

function updateStats() {
  document.getElementById("totalStudents").textContent = students.length;

  const eligibleCount = students.filter(s => s.eligible).length;
  document.getElementById("eligibleStudents").textContent = eligibleCount;

  if (students.length === 0) {
    document.getElementById("topMarks").textContent = "—";
    document.getElementById("averageMarks").textContent = "—";
    return;
  }

  const top = Math.max(...students.map(s => s.marks));
  const average = students.reduce((sum, s) => sum + s.marks, 0) / students.length;

  document.getElementById("topMarks").textContent = top;
  document.getElementById("averageMarks").textContent = average.toFixed(1);
}

function linearSearch() {
  const roll = Number(document.getElementById("searchRoll").value);
  const result = students.find(s => s.roll === roll);

  showSearchResult(result, "Linear Search");
}

function binarySearch() {
  const roll = Number(document.getElementById("searchRoll").value);

  const sorted = [...students].sort((a, b) => a.roll - b.roll);
  let low = 0;
  let high = sorted.length - 1;
  let result = null;

  while (low <= high) {
    const mid = Math.floor((low + high) / 2);

    if (sorted[mid].roll === roll) {
      result = sorted[mid];
      break;
    }

    if (sorted[mid].roll < roll) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  showSearchResult(result, "Binary Search");
}

function showSearchResult(student, method) {
  const box = document.getElementById("searchResult");

  if (!student) {
    box.innerHTML = `<strong>${method}:</strong> Student not found.`;
    return;
  }

  box.innerHTML = `
    <strong>${method} found:</strong><br>
    Roll No: ${student.roll}<br>
    Name: ${escapeHtml(student.name)}<br>
    Marks: ${student.marks}<br>
    Scholarship: ${student.eligible ? "Eligible" : "Not Eligible"}
  `;
}

function sortByMarks() {
  // Bubble Sort
  for (let i = 0; i < students.length - 1; i++) {
    for (let j = 0; j < students.length - i - 1; j++) {
      if (students[j].marks < students[j + 1].marks) {
        const temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }

  render();
  showMessage("Students sorted by marks using Bubble Sort.");
}

function deleteStudent(roll) {
  const index = students.findIndex(s => s.roll === roll);

  if (index !== -1) {
    students.splice(index, 1);
    render();
    showMessage("Student deleted successfully.");
  }
}

function renderEligible() {
  const box = document.getElementById("eligibleList");
  const eligible = students.filter(s => s.eligible);

  if (eligible.length === 0) {
    box.innerHTML = `<div class="empty">No eligible students found.</div>`;
    return;
  }

  box.innerHTML = eligible.map(s => `
    <div class="student-item">
      <div>
        <strong>${escapeHtml(s.name)}</strong>
        <small>Roll No: ${s.roll} · Marks: ${s.marks}</small>
      </div>
      <span class="badge yes">Eligible</span>
    </div>
  `).join("");
}

function renderTopStudent() {
  const box = document.getElementById("topStudent");

  if (students.length === 0) {
    box.textContent = "No data available.";
    return;
  }

  let top = students[0];

  for (let i = 1; i < students.length; i++) {
    if (students[i].marks > top.marks) {
      top = students[i];
    }
  }

  box.innerHTML = `
    <strong>${escapeHtml(top.name)}</strong>
    <span>Roll No: ${top.roll} · ${top.marks} marks ·
    ${top.eligible ? "Scholarship Eligible" : "Not Eligible"}</span>
  `;
}

function loadDemoData() {
  students = [
    { roll: 101, name: "Rahul", marks: 82, income: 250000 },
    { roll: 102, name: "Priya", marks: 91, income: 180000 },
    { roll: 103, name: "Aman", marks: 68, income: 220000 },
    { roll: 104, name: "Simran", marks: 76, income: 350000 },
    { roll: 105, name: "Karan", marks: 88, income: 290000 }
  ];

  students.forEach(s => s.eligible = checkEligibility(s));
  render();
  showMessage("Demo data loaded.");
}

function clearAll() {
  if (students.length === 0) return;

  if (confirm("Delete all student records?")) {
    students = [];
    render();
    showMessage("All records cleared.");
  }
}

function escapeHtml(text) {
  const div = document.createElement("div");
  div.textContent = text;
  return div.innerHTML;
}

render();

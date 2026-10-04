# 🎓 ScholarTrack – Student Scholarship Management System

A **DSA Minor Project** developed to manage student records and check scholarship eligibility.

## 👥 Team Members

- **Nitin Sharma**
- **Piyush**
- **Shivam Chambail**

**College:** CGC Landran  
**Course:** B.Tech – Artificial Intelligence & Data Science

---

## 📌 Project Overview

ScholarTrack is a web-based Student Scholarship Management System.

The system stores student details and automatically checks whether a student is eligible for the scholarship based on marks and family income.

---

## 🏆 Eligibility Criteria

A student is eligible when **both conditions** are satisfied:

- Marks ≥ **75%**
- Annual Family Income ≤ **₹3,00,000**

```text
Eligible = Marks >= 75 AND Income <= 300000
```

---

## 🧠 DSA Concepts Used

- Structure
- Singly Linked List
- Array
- Insertion
- Deletion
- Traversal
- Linear Search
- Binary Search
- Bubble Sort
- Counting
- Functions

---

## 💻 Technology Stack

**Frontend**
- HTML
- CSS
- JavaScript

**Backend**
- Node.js
- Express.js

**Database**
- PostgreSQL

**Deployment**
- Render

---

## ⚙️ Main Features

- Add student records
- Delete student records
- Display student records
- Check scholarship eligibility
- Linear Search
- Binary Search
- Sort students by marks
- Count total students
- Count eligible students
- Find highest-scoring student

---

## 🏗️ Project Structure

```text
ScholarTrack/
│
├── public/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── database/
│   └── schema.sql
│
├── server.js
├── package.json
├── render.yaml
└── README.md
```

---

## 🔄 Working

```text
Enter Student Details
        ↓
Check Marks & Income
        ↓
Calculate Eligibility
        ↓
Store Student Record
        ↓
Search / Sort / Delete
        ↓
Display Results
```

---

## 🚀 Run Locally

Install dependencies:

```bash
npm install
```

Set the PostgreSQL database URL:

```text
DATABASE_URL=your_database_url
```

Start the server:

```bash
npm start
```

Then open:

```text
http://localhost:10000
```

---

## ☁️ Deployment

The project can be deployed using **Render** with:

```text
Build Command: npm install
Start Command: npm start
```

The PostgreSQL connection is configured using the `DATABASE_URL` environment variable.

---

## 📚 Learning Outcomes

This project helped us understand:

- Practical implementation of DSA
- Searching and sorting algorithms
- Linked-list based record management
- Database connectivity
- REST APIs
- Frontend and backend integration

---

## 🎓 Academic Project

This project is developed as a **DSA Minor Project** for the B.Tech Artificial Intelligence & Data Science course.

### Team

**Nitin Sharma | Piyush | Shivam Chambail**

**CGC Landran**

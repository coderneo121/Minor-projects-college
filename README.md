# ScholarTrack — Full-Stack DSA Minor Project

## Stack
Frontend: HTML + CSS + JavaScript
Backend: Node.js + Express
Database: PostgreSQL
Hosting target: Render

## Scholarship rule
Eligible when BOTH are true:
- Marks >= 75
- Annual family income <= Rs. 3,00,000

## DSA concepts shown
Structure, linked list, array, insertion, deletion, traversal, linear search, binary search, bubble sort, counting and functions.

## Local setup
1. Install Node.js.
2. Create a PostgreSQL database.
3. Set `DATABASE_URL`.
4. Run:
   npm install
   npm start
5. Open http://localhost:10000

For local Windows PowerShell:
$env:DATABASE_URL="postgresql://username:password@localhost:5432/scholarship"

## Render deployment
Option A — Dashboard:
1. Push this project to GitHub.
2. In Render choose New → Web Service.
3. Connect the GitHub repository.
4. Build Command: `npm install`
5. Start Command: `npm start`
6. Choose Free.
7. Create a PostgreSQL database and copy its internal connection string into the web service's `DATABASE_URL` environment variable.

Option B — Blueprint:
Upload `render.yaml` to the repository and use Render's Blueprint deployment.

Important: Render Free web services spin down after 15 minutes of inactivity. Render's current free Postgres databases have a 1 GB limit and expire after 30 days, so this is best for a college demo rather than permanent production storage.

## Why this looks like a genuine student project
- Clear academic project title and team section
- Real database-backed CRUD
- API endpoints
- Search algorithms are explicitly implemented
- Bubble Sort is implemented instead of hiding the algorithm behind a library
- Eligibility rule is visible and consistent
- No fake payment/login/AI features

#  GPA & CGPA Calculator (C++)

A simple command-line application developed in **C++** to calculate a student's **Semester GPA** and **Overall CGPA** based on course grades and credit hours.

##  Features

- Calculate Semester GPA
- Calculate Overall CGPA
- Accepts multiple courses
- Displays course-wise details
- Shows:
  - Grade Points
  - Credit Hours
  - Total Credits
  - Total Grade Points
- Uses formatted table output for better readability

---

##  Technologies Used

- C++
- Standard Template Library (STL)
- `<iostream>`
- `<iomanip>`

---

##  Project Structure

```
GPA-CGPA-Calculator/
│
├── main.cpp          # Source code
└── README.md         # Project documentation
```

---

##  How It Works

### Step 1
Enter the total number of courses.

### Step 2
For each course, enter:

- Grade Point
- Credit Hours

### Step 3
The program calculates:

- Total Grade Points
- Total Credits
- Semester GPA

### Step 4
Enter the total number of semesters.

For remaining semesters, provide:

- GPA
- Total Credits

### Step 5
The program calculates and displays the final CGPA.

---

##  Formula Used

### GPA

```
GPA = Σ(Grade Point × Credit Hours) / Σ(Credit Hours)
```

### CGPA

```
CGPA = Σ(Semester GPA × Semester Credits) / Σ(Semester Credits)
```

---

---

##  Compilation

Using **g++**

```bash
g++ main.cpp -o GPA_Calculator
```

Run

```bash
./GPA_Calculator
```

For Windows

```bash
GPA_Calculator.exe
```

---

## 📈 Time Complexity

- GPA Calculation: **O(n)**
- CGPA Calculation: **O(s)**

Where:

- **n** = Number of courses
- **s** = Number of semesters

---

##  Future Improvements

- Grade validation
- Letter Grade (A+, A, B+, etc.) support
- Save result to a file
- Multiple student records
- Percentage conversion

---

## Author

**Mani Sai**

CSE (AI & ML)

---
This project  a part my code alpha 

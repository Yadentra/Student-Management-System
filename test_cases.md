# Test Cases for Student Management System

| Test Case ID | Description                      | Input             | Expected Output                      | Status |
|--------------|----------------------------------|-------------------|--------------------------------------|--------|
| TC-01        | Add a new student      | ID=1, Name=John, Age=20, Dept=CS | "Student added successfully!" | Pass/Fail |
| TC-02        | Display all students             | N/A             | List of all students with details    | Pass/Fail |
| TC-03        | Search for an existing student   | ID=1             | Student details (ID=1)              | Pass/Fail |
| TC-04        | Search for a non-existing student | ID=999          | "Student not found!"                | Pass/Fail |
| TC-05        | Delete an existing student       | ID=1             | "Student deleted successfully!"     | Pass/Fail |
| TC-06        | Delete a non-existing student    | ID=999           | "Student not found!"                | Pass/Fail |
| TC-07        | Add a student with invalid data  | ID=abc          | Error or re-prompt for correct input | Pass/Fail |
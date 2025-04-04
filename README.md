# 🏥 Hospital Patient Record Management System

A simple console-based Hospital Management System built in C to manage patient records such as name, age, disease, gender, room number, and more.

---

## 📌 Features

- ✅ Add new patient records
- ✅ View all stored patient details
- ✅ Search patient by name
- ✅ Delete a specific patient record
- ✅ Persistent data storage using binary file handling

---

## 🛠️ Technologies Used

- **Language:** C
- **Concepts:** Structs, File I/O (`fread`, `fwrite`, `fopen`, `fclose`), String handling, Menu-driven programming

---

## 🗂️ File Structure

hospital-patient-record ├── main.c # Main source file ├── patients.dat # Binary file to store patient records (auto-generated) └── README.md # Project documentation

yaml
Copy
Edit

---

## ⚙️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/hospital-patient-record.git
   cd hospital-patient-record
Compile the code:

bash
Copy
Edit
gcc main.c -o hospital
Run the program:

bash
Copy
Edit
./hospital
📸 Sample Output
mathematica
Copy
Edit
Welcome to Sanjana Hospital Management System

    1. Add Information
    2. View Information
    3. Search for Patient
    4. Delete Information
    5. Exit

Enter your choice:
📚 Learning Highlights
Practical experience with structs for real-world data modeling

Implementation of persistent storage using binary files

Handling string input and dynamic searching

Writing modular, reusable C functions

🙌 Contributions
Feel free to fork this project and enhance it with:

A GUI using C++ or Python (Tkinter/Qt)

A web interface using HTML/CSS/JavaScript + a backend

Database integration using MySQL or SQLite

📄 License
This project is open-source and available under the MIT License.

🌟 Acknowledgment
Built as a part of my learning journey in systems programming and healthcare software logic. Feedback and suggestions are welcome!

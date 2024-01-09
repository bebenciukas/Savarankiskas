using System.Text;

namespace Savarankiskas2
{
    public partial class Form1 : Form
    {
        private string chosenFilePath;
        private List<Student> students = new List<Student>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
        }

        private void DisplaySortedData(List<Student> students)
        {
            students = students.OrderBy(s => s.Surname.First()).ThenBy(s => s.Surname).ToList();
            string header = "Pavarde     Vardas      Galutinis(Vid.) Galutinis(Med.)";
            string separator = "------------------------------------------------------";
            string rowFormat = "{0,-12} {1,-12} {2,-17:F2} {3,-17:F2}";

            StringBuilder sortedData = new StringBuilder();
            sortedData.AppendLine(header);
            sortedData.AppendLine(separator);

            foreach (var student in students)
            {
                sortedData.AppendLine(string.Format(rowFormat, student.Surname, student.Name, student.FinalGradeAverage, student.FinalGradeMedian));
            }

            textBox1.Text = sortedData.ToString();
        }


        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var fileContent = string.Empty;
            var filePath = string.Empty;

            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    filePath = openFileDialog.FileName;
                    var fileStream = openFileDialog.OpenFile();

                    using (StreamReader reader = new StreamReader(fileStream))
                    {
                        fileContent = reader.ReadToEnd();
                        students.Clear(); 
                        ReadDataFromFile(fileContent, students);
                        students = students.OrderBy(s => s.Surname.First()).ToList();
                        DisplaySortedData(students);
                    }
                }
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Files|*.txt|All Files|*.*";

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                chosenFilePath = saveFileDialog.FileName;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Files|*.txt|All Files|*.*";

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = saveFileDialog.FileName;
                System.IO.File.Create(filePath).Close();
                MessageBox.Show($"Failas sukurtas!");
            }
        }
        private void ReadDataFromFile(string fileContent, List<Student> students)
        {
            string[] lines = fileContent.Split('\n', StringSplitOptions.RemoveEmptyEntries);
            for (int i = 1; i < lines.Length; i++)
            {
                string[] parts = lines[i].Trim().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length >= 8)
                {
                    string surname = parts[0];
                    string name = parts[1];
                    int hw1 = int.Parse(parts[2]);
                    int hw2 = int.Parse(parts[3]);
                    int hw3 = int.Parse(parts[4]);
                    int hw4 = int.Parse(parts[5]);
                    int hw5 = int.Parse(parts[6]);
                    int exam = int.Parse(parts[7]);
                    Student student = new Student
                    {
                        Surname = surname,
                        Name = name
                    };
                    student.AddHomeworkGrade(hw1);
                    student.AddHomeworkGrade(hw2);
                    student.AddHomeworkGrade(hw3);
                    student.AddHomeworkGrade(hw4);
                    student.AddHomeworkGrade(hw5);
                    student.ExamGrade = exam;

                    students.Add(student);
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
      
            students = students.OrderBy(s => s.Surname.First()).ThenBy(s => s.Surname).ToList();

            // Save the sorted data using the chosen file path
            if (!string.IsNullOrEmpty(chosenFilePath))
            {
                SaveDataToFile(chosenFilePath, students);

                // Display the sorted information in textBox1
                DisplaySortedData(students);
            }
            else
            {
                MessageBox.Show("Pasirinkite iðvesties failà");
            }
        }

        private void SaveDataToFile(string filePath, List<Student> students)
        {
            // Create a StringBuilder to store the data
            StringBuilder data = new StringBuilder();

            // Add header
            data.AppendLine("Pavarde     Vardas      Galutinis(Vid.) Galutinis(Med.)");
            data.AppendLine("------------------------------------------------------");
            foreach (var student in students)
            {
                data.AppendLine($"{student.Surname,-12} {student.Name,-12} {student.FinalGradeAverage,-17:F2} {student.FinalGradeMedian,-17:F2}");
            }
            File.WriteAllText(filePath, data.ToString());
        }
    }
}

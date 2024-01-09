using System;
using System.Collections.Generic;
using System.Linq;

namespace Savarankiskas2
{
    public class Student
    {
        public Student()
        {
            HomeworkGrades = new List<int>();
        }

        public void AddHomeworkGrade(int grade)
        {
            HomeworkGrades.Add(grade);
        }
        public string Name { get; set; }
        public string Surname { get; set; }
        public List<int> HomeworkGrades { get; set; }
     
        public int ExamGrade { get; set; }
        public double FinalGradeAverage
        {
            get
            {
                if (HomeworkGrades == null || HomeworkGrades.Count == 0)
                    return 0.6 * ExamGrade;

                double average = HomeworkGrades.Average();
                return 0.4 * average + 0.6 * ExamGrade;
            }
        }

        public double FinalGradeMedian
        {
            get
            {
                if (HomeworkGrades == null || HomeworkGrades.Count == 0)
                    return 0.6 * ExamGrade;

                var sortedGrades = HomeworkGrades.OrderBy(g => g).ToList();
                int count = sortedGrades.Count;

                if (count % 2 == 0)
                    return (sortedGrades[count / 2 - 1] + sortedGrades[count / 2]) / 2.0;
                else
                    return sortedGrades[count / 2];
            }
        }

    }
}

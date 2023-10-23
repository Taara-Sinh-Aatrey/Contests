marks = {'Lakshman' : {'Maths' : 90, 'English' : 75, 'Social Science' : 10}}

def convertMarks(marks):
  Grades = dict()
  for person, mark in marks.items():
      grades = dict()  
      for subject, score in mark.items():
          if score > 90:
              grades[subject] = 'A'
          elif score > 80:
              grades[subject] = 'B'
          elif score > 70:
              grades[subject] = 'C'
          elif score > 60:
              grades[subject] = 'D'
          elif score > 50:
              grades[subject] = 'E+'
          elif score > 40:
              grades[subject] = 'E'
          else:
              grades[subject] = 'F'
      Grades[person] = grades
  return Grades
    
Grades = convertMarks(marks)
print(Grades)
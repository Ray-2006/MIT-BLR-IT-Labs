class Student {
    String name;
    int id;

    void setStudent(String name, int id) {
        this.name = name;
        this.id = id;
    }
}

class Sports extends Student {
    int s_grade;

    void setSports(int grade) {
        this.s_grade = grade;
    }
}

class Exam extends Sports {
    int e_grade;

    void SetExam(int grade) {
        this.e_grade = grade;
    }
}

class Results extends Exam {
    String final_result;

    void calcResult() {
        int total = s_grade + e_grade;
        if (total >= 100)
            final_result = "Pass";
        else
            final_result = "Fail";
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Sports Grade: " + s_grade);
        System.out.println("Exam Grade: " + e_grade);
        System.out.println("Final Result: " + final_result);
    }
}

public class Q3_examScore {
    public static void main(String[] args) {
        Results r = new Results();
        r.setStudent("Name1", 100);
        r.setSports(55);
        r.SetExam(60);
        r.calcResult();
        r.display();
    }
}
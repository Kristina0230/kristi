import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class StudentSearch {

    private static final String FILE_NAME = "students.txt";

    public static void main(String[] args) {
        Student[] students = readStudentsFromFile();
        System.out.println("Число студентов: " + students.length);

        // поиск по ключевому полю
        int searchId = 10;
        long startTime = System.nanoTime();
        Student student = sequentialSearch(students, searchId);
        long endTime = System.nanoTime();
        long timeElapsed = endTime - startTime;
        System.out.println("Метод последовательного поиска");
        System.out.println("Студент с идентификатором " + searchId + ": " + student);
        System.out.println("Время выполнения: " + timeElapsed + " наносекунд");

        // поиск в неотсортированных древовидно структурированных массивах
        startTime = System.nanoTime();
        student = treeSearch(students, searchId);
        endTime = System.nanoTime();
        timeElapsed = endTime - startTime;
        System.out.println("\nМетод поиска в неотсортированных древовидно структурированных массивах");
        System.out.println("Студент с идентификатором " + searchId + ": " + student);
        System.out.println("Время выполнения: " + timeElapsed + " наносекунд");

        // бинарный поиск
        startTime = System.nanoTime();
        student = binarySearch(students, searchId);
        endTime = System.nanoTime();
        timeElapsed = endTime - startTime;
        System.out.println("\nМетод бинарного поиска");
        System.out.println("Студент с идентификатором " + searchId + ": " + student);
        System.out.println("Время выполнения: " + timeElapsed + " наносекунд");

        // поиск интерполяцией
        startTime = System.nanoTime();
        student = interpolationSearch(students, searchId);
        endTime = System.nanoTime();
        timeElapsed = endTime - startTime;
        System.out.println("\nМетод поиска интерполированием");
        System.out.println("Студент с идентификатором " + searchId + ": " + student);
        System.out.println("Время выполнения: " + timeElapsed + " наносекунд");

        // метод Фибоначчи для поиска в отсортированном массиве
        startTime = System.nanoTime();
        student = fibonacciSearch(students, searchId);
        endTime = System.nanoTime();
        timeElapsed = endTime - startTime;
        System.out.println("\nМетод Фибоначчи для поиска в отсортированном массиве");
        System.out.println("Студент с идентификатором " + searchId + ": " + student);
        System.out.println("Время выполнения: " + timeElapsed + " наносекунд");
    }
}
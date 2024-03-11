import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Lambada {

    public static boolean isEven(int number){
        return number%2 == 0;
    }
    public static void main(String[] args) {
//        List<String> cities = List.of("kolhapur", "pune", "mumbai");
        // older way
//        Collections.sort(cities, new Comparator<String>() {
//            @Override
//            public int compare(String o1, String o2){
//                return o1.compareToIgnoreCase(o2);
//            }
//        });
        // newer way using lambada
        // lambada's are anonymous functions
//        Collections.sort(cities, (o1, o2) -> o1.compareToIgnoreCase(o2));

//        cities.forEach((city) -> System.out.println(city));

        var numbers = List.of(2.10, 43, 12, 50);

        // Streams
        var evenNumbers = numbers.stream()
                .filter(num -> isEven(num))
                .toList();
    }
}

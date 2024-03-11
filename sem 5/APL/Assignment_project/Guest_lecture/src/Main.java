import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        // generics with collections for compile time safety
        // List<String> list = new ArrayList<>(); 
        // 
        //
        // list.add("Kolhapur");
        // list.add("Pune");
        // list.add("Mumbai");

        List<String> list = Arrays.asList("kolhapur", "pune", "mumbai"); // unmodifiable list
        // list.add("nagpur"); // UnsupportedOperationException
        String givenCity = "Patiala";
        boolean isCityFound = false;
        // imperative programming
        for (String s  : list) {
            if(s.equals(givenCity)){
                System.out.println("City Found");
                isCityFound = true;
                break;
            }
        }
        if(!isCityFound)
            System.out.println("City not Found");

        // declarative programming
        if(list.contains(givenCity)){
            System.out.println("City Found");
        } else {
            System.out.println("City Not Found");
        }

        

        System.out.println(list);
    }
}

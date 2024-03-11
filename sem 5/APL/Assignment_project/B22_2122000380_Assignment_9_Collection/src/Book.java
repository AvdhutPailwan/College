public class Book {
    private int accesionNum;

    public String getTitle() {
        return title;
    }

    private String title;
    private String author;
    private double price;
    private int edition;

    public Book(int accesionNum, String title, String author, double price, int edition) {
        this.accesionNum = accesionNum;
        this.title = title;
        this.author = author;
        this.price = price;
        this.edition = edition;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(this.getClass() != obj.getClass() || obj == null) return false;
        Book obj1 = (Book) obj;
        return this.title.equals(obj1.getTitle());
    }

    @Override
    public int hashCode(){
        return title.hashCode();
    }
}

package Entity;

public class Book {
    private String title;
    private String author;
    private String isbn;
    private boolean isAvailable;
    private String borrower;
    private String dueDate;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isAvailable = true;
        this.borrower = "";
        this.dueDate = "";
    }

    // Getters and setters
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getIsbn() {
        return isbn;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public String getBorrower() {
        return borrower;
    }

    public String getDueDate() {
        return dueDate;
    }

    public void setBorrower(String borrower) {
        this.borrower = borrower;
    }

    public void setDueDate(String dueDate) {
        this.dueDate = dueDate;
    }

    public void setAvailable(boolean available) {
        isAvailable = available;
    }

    @Override
    public String toString() {
        return title + "," + author + "," + isbn + "," + isAvailable + "," + borrower + "," + dueDate;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Book book = (Book) o;
        return isbn.equals(book.isbn);
    }

    @Override
    public int hashCode() {
        return isbn.hashCode();
    }

    public static Book fromString(String str) {
        String[] parts = str.split(",");
        Book book = new Book(parts[0], parts[1], parts[2]);
        book.setAvailable(Boolean.parseBoolean(parts[3]));
        book.setBorrower(parts[4]);
        book.setDueDate(parts[5]);
        return book;
    }
}
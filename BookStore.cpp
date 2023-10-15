
/**
 * TODO: Implement all the BookStore methods below.
 * Note you'll have to remain inside the CPSC131::BookStore namespace.
 */

//
#include "BookStore.hpp"


//
#include <iostream>
#include <sstream>
#include <string>


//
using std::cout, std::cin, std::endl;
using std::string, std::to_string;
using std::stringstream;


//
namespace CPSC131::BookStore
{

	/// Your welcome
	BookStore::BookStore() {}
	
	/**
	 * Adjust the store's account balance
	 * Should accept positive or negative adjustments
	 */
	void BookStore::adjustAccountBalance(int adjustment)
	{
		this->account_balance_ += adjustment;

	}
	
	/**
	 * Return the store's current account balance
	 */
	int BookStore::getAccountBalance() const
	{
		return this->account_balance_;
	}
	
	/**
	 * Find a book by its ISBN
	 * 
	 * Return this->bookList.end() if the book isn't found.
	 * 
	 * Return an interator pointing to the Book if it is found.
	 */
	DoublyLinkedList::DoublyLinkedList<Book>::Iterator BookStore::findBook(std::string isbn) const
	{
		for (auto it = bookList.begin(); it != bookList.end(); ++it) {
        	if (it.getCursor()->getElement().getIsbn() == isbn) {
				return it; // Return the iterator pointing to the found book
			}
		}
		return bookList.end(); 
	}
	
	/**
	 * Check whether a book exists, by its ISBN
	 * 
	 * Return true if it exists, or false otherwise
	 */
	bool BookStore::bookExists(std::string isbn) const
	{
		for (const auto& book : bookList) {
        if (book.getIsbn() == isbn) {
            return true;
        }
    }
    return false;
	}
	
	/**
	 * Check the quantity of stock we have for a particular book, by ISBN
	 * 
	 * If the book doesn't exist, just return 0
	 */
	size_t BookStore::getBookStockAvailable(std::string isbn) const
	{
		//	TODO: Your code here
		 for (const auto& book : bookList) {
			if (book.getIsbn() == isbn) {
				return book.getStockAvailable();
			}
		}
		
		return 0;
	}
	
	/**
	 * Locate a book by ISBN and return a reference to the Book
	 * 
	 * If the book doesn't exist, throw an exception
	 */
	Book& BookStore::getBook(std::string isbn) const
	{
		for (auto it = bookList.begin(); it != bookList.end(); ++it) {
			if (it.getCursor()->getElement().getIsbn() == isbn) {
				// Found the book, return a reference to it
				return it.getCursor()->getElement();
			}
    }

    // Book not found, throw an exception
    throw std::runtime_error("Book not found with ISBN: " + isbn);
	}
	
	/**
	 * Take a Book instance and add it to inventory
	 * 
	 * If the book's ISBN already exists in our store,
	 * 	simply adjust account balance by the book's price and quantity,
	 * 	but ignore other details like title and author.
	 * 
	 * If the book's ISBN doesn't already exist in our store,
	 * 	adjust our account balance and push the book into our list
	 */
	void BookStore::purchaseInventory(const Book& book)
	{
		//	TODO: Your code here
		
		if(bookExists(book.getIsbn())){
			std::cout << "BOOK EXISTS " << book.getStockAvailable() << std::endl;
			auto it = findBook(book.getIsbn());
			it.getCursor()->getElement().adjustStockAvailable(book.getStockAvailable());
			std::cout << "BOOK EXISTS " << it.getCursor()->getElement().getStockAvailable() << std::endl;
			adjustAccountBalance(-1 * book.getPriceCents() * book.getStockAvailable());
		}
		else{
			std::cout << "Book no exist " << book.getTitle() << std::endl;
			adjustAccountBalance(-1 * book.getPriceCents()  * book.getStockAvailable());
			bookList.push_back(book);
		}
	}
	
	/**
	 * Take some book details and add the book to our inventory.
	 * 
	 * Use the same rules as the other overload for this function.
	 * 
	 * You might want to avoid repeating code by simply building a Book
	 * 	object from the details, then calling the other overload
	 * 	with the new Book object.
	 */
	void BookStore::purchaseInventory(
		std::string title, std::string author, std::string isbn,
		size_t price_cents,
		size_t unit_count
	)
	{
		Book newbook = Book(title, author, isbn, price_cents, unit_count);

    // Call the other overload of the function with the new Book object
    	purchaseInventory(newbook);
	}
	
	/**
	 * Print out inventory.
	 * Should be in a particular way to earn unit test points.
	 * Example (ignore the asterisks at the left of this comment block):
	 * 
	 * *** Book Store Inventory ***
	 * "Book1", by Author1 [123] (5 in stock)
	 * "Book2", by Author2 [456] (19 in stock)
	 * 
	 * Should print a trailing std::endl after the last book line, for the unit tests
	 */
	void BookStore::printInventory() const
	{
		for (const auto& book : bookList) {
			cout << "\"" <<  book.getTitle() << "\", by " << book.getAuthor() << " [" << book.getIsbn() << "] ("  << book.getStockAvailable() <<  " in stock)" << endl;
		}
	}
	
	/**
	 * Sell a book to a customer!
	 * 
	 * Takes the ISBN of the book, the selling price of the book, and the quantity of books sold
	 * 
	 * Uses the same rules as the other overload.
	 * 
	 * You may wish to just grab a reference to the book and call the other overload,
	 * 	to avoid repeating code
	 */
	void BookStore::sellToCustomer(std::string isbn, size_t price_cents, size_t quantity)
	{
		Book& bookToSell = getBook(isbn);
		// if (bookToSell.getStockAvailable() >= quantity) {
		// 	// Calculate the total revenue
		// 	size_t totalRevenue = price_cents * quantity;
		// 	// Update the stock quantity
		// 	bookToSell.decrementStock(quantity);
		// 	// Update the store's total revenue
		// 	totalRevenue += totalRevenue;
		// 	// Handle the sale transaction (e.g., update records, generate a receipt, etc.)
		// 	// You can also return the total revenue if needed
		// 	// return totalRevenue;
		// } else {
		// 	// Handle the case where there is not enough stock to fulfill the sale
		// 	// You might want to return an error code or throw an exception.
		// }
		return sellToCustomer(bookToSell, price_cents, quantity);
	}
	
	/**
	 * Sell a book to a customer!
	 * 
	 * Takes a Book reference, the selling price of the book, and the quantity of books sold
	 * 
	 * If we don't have enough of this book in stock for the quantity the customer wants to purchase,
	 * 	throw an std::range_error
	 * 
	 * Otherwise, adjust the stock available in our store, and update our account balance.
	 */
	void BookStore::sellToCustomer(Book& book, size_t price_cents, size_t quantity)
	{
		Book& bookToSell = getBook(book.getIsbn());
		if (bookToSell.getStockAvailable() < quantity) {
       	 throw std::range_error("Not enough stock available for the customer's request");
		}
		// Calculate the total revenue
		size_t totalRevenue = price_cents * quantity;
		// Update the stock quantity
		book.adjustStockAvailable(-1 * quantity);
		// Update the store's account balance
		// Assuming you have an account balance attribute in your BookStore class
		adjustAccountBalance(totalRevenue);
	}
}








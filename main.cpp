
/**
 * You don't need to edit this file, although you can if you wish.
 * This source file will not be graded.
 * 
 * This is a live TUI for the BookStore you're working on. You can
 * use it to manually play around in your store.
 */

//
#include "BookStore.hpp"


//
#include <iostream>
#include <string>
#include <vector>


//
using std::cout, std::cin, std::endl;
using std::string;


//
using CPSC131::BookStore::BookStore, CPSC131::BookStore::Book;


//	PROTO
void menuLoop();
void purchaseInventory();
void viewInventory();
void sellToCustomer();
string getLine();

//	Globals: Not a great practice, but very good for a lazy professor making starter code :)
BookStore store;
//
int main()
{

	BookStore store;
	
	//
	std::vector<Book> books = {
		Book("Brainwashing is a Cinch!", "James Maratta", "B001NDNB7C", 900),
		Book("Catflexing - A Catlover's Guide to Weight Training, Aerobics, and Stretching", "Stephanie Jackson", "0898159407", 550),
		Book("How to Enjoy Your Weeds", "Audrey Wynne Hatfield", "080693042X", 1200),
		Book("How to Teach Quantum Physics to Your Dog", "Chad Orzel", "1416572295", 2000),
		Book("How to Train Goldfish Using Dolphin Training Techniques", "C. Scott Johnson", "0533112923", 100)
	};
	size_t quantity = 50;
	for ( Book b : books ) {
			b.adjustStockAvailable(quantity);
			quantity--;
		
		store.purchaseInventory(b);
	}
	cout << store.getAccountBalance() << endl;
	store.purchaseInventory(Book("Ninja Mind Control", "Ashida Kim", "1435769244", 999, 3));
	cout << store.getBookStockAvailable("1435769244") << endl;
	store.purchaseInventory(Book("Bla", "Bla", "1435769244", 1000, 2));
	cout << store.getBookStockAvailable("1435769244") << endl;


	// CPSC131::DoublyLinkedList::DoublyLinkedList<int> list1;
	// list1.push_back(1);
	// list1.push_back(2);
	// list1.push_back(3);
	// list1.push_back(4);
	// list1.push_back(5);
	// //cout << list1.size();
	// for(size_t i = 0; i < list1.size(); i++){
	// 	cout << list1.at(i) << endl;
	// }
	// for(auto it = list1.begin(); it != list1.end(); it++){
	// 	cout << (*it) << endl;
	// }

	//
	
	// CPSC131::DoublyLinkedList::DoublyLinkedList<int> list1;
	// for ( size_t i = 0; i < 20; i++ ) {
	// 	int value = (i * 3) - 30;
	// 	list1.push_back(value);
	// 	// std::cout << "value at  " << i << " is " << value << std::endl;
	// }
	// CPSC131::DoublyLinkedList::DoublyLinkedList<int> list2(list1);
	// cout << list2.at(20) << endl;
	// cout << list2.at(19) << endl;
	// for ( size_t i = 0; i < 20; i++ ) {
	// 	cout << list2.at(i) << endl;
	// }
	// auto list2 = list1;
				

	//CPSC131::DoublyLinkedList::DoublyLinkedList<int> list1;
	// 			list.push_front(19);
	// 			list.push_front(12);
	// 			list.push_front(-129878);
	// 			list.push_front(228764364);
	// 			list.push_front(119991111);
	// 			list.push_front(0);
	// 			list.push_front(1900000000);
	// auto list2 = list;
	// for(size_t i = 0; i < list.size(); i++){
	// 	cout << list.at(i) << endl;
	// }
	// cout << "_________________" << endl;
	// cout << list.size() << endl;
	// cout << list2.size() << endl;
	// for(size_t i = 0; i < list2.size(); i++){
	// 	cout << list2.at(i) << endl;
	// }
	// for ( size_t i = 0; i < 20; i++ ) {
	// 	int value = (i * 3) - 30;
	// 	list1.push_back(value);
	// }

	// auto list2 = list1;
	// list2.clear();
	// list2.push_back(27);
	// list2.push_back(24);
	// list2.push_back(21);
	// list2.push_back(18);
	// list2.push_back(15);
	// list2.push_back(12);
	// list2.push_back(9);
	// list2.push_back(6);
	// list2.push_back(3);
	// list2.push_back(0);
	// list2.push_back(-3);
	// list2.push_back(-6);
	// list2.push_back(-9);
	// list2.push_back(-12);
	// list2.push_back(-15);
	// list2.push_back(-18);
	// list2.push_back(-21);
	// list2.push_back(-24);
	// list2.push_back(-27);
	// list2.push_back(-30);
	
	// list1.reverse();
	// cout << list1.size() << endl;
	// for ( size_t i = 0; i < list1.size(); i++ ) {
	// 	cout << list1.at(i) << endl;
	// }
	
	// cout << list1.size() << endl;
	// for ( int i = 0; i < 100; i++ ) {
	// 				list.push_front(i * 2);
	// 				list.push_back(i * 2);
	// 			}
	// cout << list.size() << endl;
	// for ( int i = 0; i < 50; i++ ) {
	// 				list.pop_front();
	// 				list.pop_back();
	// 			}
	// cout << list.size() << endl;
	// cout << list.empty() << endl;
	// for ( int i = 0; i < 50; i++ ) {
	// 				list.pop_front();
	// 				list.pop_back();
	// 				cout << "Popped " << i << endl;
	// 			}
	// 			cout << list.size() << endl;
	// cout << list.empty() << endl;
	// //std::cout << "list is " << list.empty() << std::endl;
	
	// auto itr = list.begin();
	// itr++;
	// cout << *itr << endl;
	// ++itr;
	// cout << *itr << endl;
	// itr += 10;
	// cout << *itr << endl;
	// itr -= 4;
	// cout << *itr << endl;
	// itr--;
	// cout << *itr << endl;
	// --itr;
	// cout << *itr << endl;
	// auto itr2 = itr;
	// cout << (itr == itr2) << endl;
	// itr2++;
	// cout << (itr != itr2) << endl;
	// itr += 5000;
	// cout << (itr == list.end()) << endl;


	// cout << list.at(0) << endl;
	// cout << list.at(3) << endl;
	// cout << list.at(16) << endl;
	// cout << list.size() << endl;
	// list.insert_after(7, 119);
	// cout << list.at(8) << " Should be 119" << endl;
	// for ( int i = 0; i < 20; i++ ) {
	// 	cout << list.at(i) << endl;
	// }
	// list.insert_after(13, 181);
	// cout << list.size() << " Should be 22" << endl;
	// cout << list.at(8) << " Should be 119" << endl;
	// cout << list.at(14) << " Should be 181" << endl;
	// list.push_front(1011);
	// list.push_back(1012);
	// cout << list.size() << " Should be 24" << endl;
	// cout << list.at(0) << " Should be 1011" << endl;
	// cout << list.at(list.size() - 1) << " Should be 1012" << endl;
	// cout << list.front() << " Should be 1011" << endl;
	// cout << list.back() << " Should be 1012" << endl;
	// CPSC131::DoublyLinkedList::DoublyLinkedList<int> list2;
	// list2.push_front(19);
	


	//std::cout << "SIZE is " << list.head_k() << std::endl;
	// for ( size_t i = 0; i < 20; i++ ) {
	// 	//std::cout << "Checking after at  " << i << " it is " << list.at(i) << std::endl;
	// }
	// std::cout << "SIZE is " << list.size() << std::endl;
	// list.assign(22, 50504);
	// std::cout << "SIZE is " << list.size() << std::endl;
	// std::cout << "element is " << list.at(0) << std::endl;
	// // auto itr = list.begin();
	// // std::cout << (*itr) << std::endl;
	// // itr++;
	// // ++itr;
	// // --itr;
	// // std::cout << (*itr) << std::endl;
	

	// std::cout << "SIZE is " << list.size() << std::endl;
	// //std::cout << "Last is " << list.front() << std::endl;
	// list.push_front(100);
	// std::cout << "SIZE is " << list.size() << std::endl;
	// std::cout << "Last is " << list.front() << std::endl;
	// list.clear();
	// std::cout << "SIZE is " << list.size() << std::endl;
	//std::cout << "Last is " << list.front() << std::endl;
	
	
	
	// menuLoop();
	
	// //
	// cout << "Program exiting" << endl;
	
	return 0;
}


//
void menuLoop()
{
	//
	while (true)
	{
		//
		auto balance = store.getAccountBalance();
		
		//
		cout
			<< endl << endl << endl
			<< "*** Book Store - Main Menu ***" << endl
			<< endl
			<< "Account balance: " << balance << " cents" << (balance >= 0 ? "" : " (Oh nyo)") << endl
			<< endl
			<< "1. Purchase inventory (add Book to store)" << endl
			<< "2. View inventory" << endl
			<< "3. Sell to customer" << endl
			<< endl
			<< "Q. Quit" << endl
			<< endl
			<< "Enter your selection ==> "
			;
		
		//
		string choice = getLine();
		cout << endl;
		
		//
		if ( choice == "1" ) {
			purchaseInventory();
		}
		else if ( choice == "2" ) {
			viewInventory();
		}
		else if ( choice == "3" ) {
			sellToCustomer();
		}
		else if ( choice == "Q" || choice == "q" ) {
			break;
		}
		else {
			cout << "Invalid choice: " << choice << endl;
		}
	}
}

//
void purchaseInventory()
{
	string title, author, isbn;
	size_t price_cents, quantity;
	
	//
	cout
		<< "Purchasing inventory ..." << endl
		<< endl
		<< "Enter book ISBN: "
		;
	isbn = getLine();
	
	//
	if ( !store.bookExists(isbn) ) {
		cout << "Enter title: ";
		title = getLine();
		cout << "Enter author: ";
		author = getLine();
	}
	
	//
	cout << "Enter wholesale price (in cents): ";
	price_cents = stoi(getLine());
	cout << "Enter quantity: ";
	quantity = stoi(getLine());
	
	//
	store.purchaseInventory(
		title, author, isbn,
		price_cents,
		quantity
	);
}


//
void viewInventory()
{
	store.printInventory();
}


//
void sellToCustomer()
{
	cout << "Selling to customer ..." << endl;
	
	string isbn;
	cout << "Enter the ISBN of the book to sell: ";
	isbn = getLine();

	size_t price;
	cout << "Enter the price per copy, in cents: ";
	price = stoi(getLine());
	
	size_t quantity;
	cout << "Enter the quantity to sell: ";
	quantity = stoi(getLine());
	
	try
	{
		store.sellToCustomer(isbn, price, quantity);
		cout << "Sale was successful" << endl;
		cout << "Sold " << quantity << " copies of ISBN:" << isbn << " at " << price << " cents each" << endl;
	}
	catch( const std::exception& e )
	{
		cout << "Failed to sell to customer: " << e.what() << endl;
	}
}

//
string getLine()
{
	const size_t BUFFER_SIZE = 8192;
	char buffer[BUFFER_SIZE];
	
	cin.clear();
	cin.getline(buffer, BUFFER_SIZE);
	
	string s = buffer;
	
	return s;
}








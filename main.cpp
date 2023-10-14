
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
	//
	
	CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
	for ( int i = 0; i < 100; i++ ) {
					list.push_front(i * 2);
					list.push_back(i * 2);
				}
	cout << list.size() << endl;
	for ( int i = 0; i < 50; i++ ) {
					list.pop_front();
					list.pop_back();
				}
	cout << list.size() << endl;
	cout << list.empty() << endl;
	for ( int i = 0; i < 50; i++ ) {
					list.pop_front();
					list.pop_back();
					cout << "Popped " << i << endl;
				}
				cout << list.size() << endl;
	cout << list.empty() << endl;
	// //std::cout << "list is " << list.empty() << std::endl;
	// for ( size_t i = 0; i < 20; i++ ) {
	// 	int value = (i * 3) - 30;
	// 	list.push_back(value);
	// 	std::cout << "value at  " << i << " is " << value << std::endl;
	// }
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








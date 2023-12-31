/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "linked_list.h"
#include <iostream>

using namespace std;


int main(){
  Linked_list<double> list1, list2;
	int x;
	/* inserting three elements into the list list1 */
	x = 1;
  list1.insert(x, list1.begin());
	x = 2;
  list1.insert(x, list1.begin());
	x = 3;
  list1.insert(x, list1.begin());
	x = 4;
  list1.insert(x, list1.begin());

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */


	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	//Test reverse();
		cout << "Reversing the list:" << endl;
		list1.reverse();
		list2.reverse();

		cout << "List 1 : "; cout << list1; cout << endl;
		cout << "List 2 : "; cout << list2; cout << endl;

//CANCELLAZIONE TEST_SET
/*NUOVO TEST_SET
	LIST1 = [ 1 , 0 , 0 , 0, 1];
*/
	Linked_list<int> list;

	x = 0;
  	list.insert(x, list.begin());
	list.insert(x, list.begin());
	list.insert(x, list.begin());
	x=1;
	list.push_back(x);
	list.insert(x, list.begin());	

	cout << "NUOVO TEST SET"; cout << endl;
	cout << list;
	
	//Test isPalindrome()
		cout << "Testo se è palindroma: "; cout << endl;
		bool flag = list.isPalindrome();
		cout << flag << endl; 

		cout << list;
	return 1;
}

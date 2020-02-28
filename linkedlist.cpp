linkedlist::linkedlist(){
	head = NULL;
	count = 0;
}

void linkedlist::insert(Robot *rp) {
	node *n;
	n = new node;
	n -> set_data(rp);
	n -> set_next(head);
	head = n;
	count++;
}

void linkedlist::remove(int n) {
	if(head == NULL)
		return;
	if((head -> get_data()) -> getRobotNum == n) {
		node *temp;
		temp = head;
		head = head->get_next();
		temp -> remove_data();
	}
	else {
		if(head ->remove(n) == 1)
			count--;
	}
}

node::node() {
	next = NULL;
	data = NULL;
}

void node::remove(int n) {
	if (next != NULL) {
		if((next -> data) -> getRobotNum == n) {
			node *temp;
			temp = next;
			next = next -> next;
			temp -> remove_data();
			delete temp;
			return(1);
		}
		else {
			return(next->remove(n));
		}
	}
	return 0;
}


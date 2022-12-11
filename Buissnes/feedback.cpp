#include "feedback.h"
#include "client.h"
#include "product.h"


//undefult constrator to feedback
Feedback::Feedback(Client & client, const string & note, Product &productData) : client(client),productData(productData)
{
	this->setNote(note);
};


//the functin check if the new note is valide and update the old one to the new note
bool Feedback::setNote(const string & note)
{
	if (note.size() >= FEEDBACK_SIZE)
	{
		cout << "The feedback is limited to "<< FEEDBACK_SIZE << "character \n";
		return false;
	}

	this->note = note;
	return true;
}

//operator<< (cout) to Feedback class
ostream & operator<<(ostream & os, const Feedback & feedback)
{
	os << "Client userName: " << feedback.client.getUserName() << "\n" << "Date: " << feedback.date
		<< "\nProduct data: \n" << feedback.productData << "\nComment: \n" << feedback.getNote() << endl;

	return os;
}

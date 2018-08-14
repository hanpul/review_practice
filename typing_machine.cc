// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	mHead = nullptr;
	mCurrNode = nullptr;
	mLength = 0;
  return;
}

void TypingMachine::HomeKey() {
	if (mHead == nullptr)
		return;

	mCurrNode = nullptr;
  return;
}

void TypingMachine::EndKey() {
	if (mHead == nullptr)
		return;

	Node *endNode = mHead;
	while (endNode->GetNextNode() != nullptr) {
		endNode = endNode->GetNextNode();
	}

	mCurrNode = endNode;
  return;
}

void TypingMachine::LeftKey() {
	if (mCurrNode == nullptr)
		return;

	mCurrNode = mCurrNode->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	Node *rightNode;
	if (mCurrNode == nullptr) {
		if (mHead == nullptr) {
			return;
		}
		mCurrNode = mHead;
	}
	else {
		rightNode = mCurrNode->GetNextNode();
		if (rightNode != nullptr) {
			mCurrNode = rightNode;
		}
	}

  return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 32 || key > 126 || mLength == 100) {
		return false;
	}

	mLength++;

	if (mCurrNode == nullptr) {
		if (mHead == nullptr) {
			Node *newNode = new Node(key);
			mCurrNode = newNode;
			mHead = newNode;
		}
		else {
			mHead->InsertPreviousNode(key);
			mCurrNode = mHead->GetPreviousNode();
			updateHead(mHead);
		}
		return true;
	}

	mCurrNode->InsertNextNode(key);
	mCurrNode = mCurrNode->GetNextNode();

	updateHead(mCurrNode);

  return true;
}

bool TypingMachine::EraseKey() {
	if (mCurrNode == nullptr) {
		return false;
	}

	if (mLength == 0)
		return false;

	Node *prevNode = mCurrNode->GetPreviousNode();

	if (prevNode != nullptr) {
		prevNode->EraseNextNode();
		mCurrNode = prevNode;
	} else {
		mHead = mCurrNode->GetNextNode();
		if (mHead != nullptr)
		    mHead->ErasePreviousNode();
		mCurrNode = nullptr;		
	}
	mLength--;
  return true;
}

void TypingMachine::updateHead(Node *node) {
	if (node == nullptr) 
		return;

	mHead = node;
	while (mHead->GetPreviousNode() != nullptr) {
		mHead = mHead->GetPreviousNode();
	}
}

std::string TypingMachine::Print(char separator) {
	Node *startNode = mHead;
	std::string result = "";

	if (startNode == nullptr) {
		if (separator != 0)
			return result + separator;
		else
			return result;
	}

	if (mCurrNode == nullptr) {
		if (separator != 0)
			result += separator;
	}

	while (startNode != nullptr) {
		result += startNode->GetData();
		if (mCurrNode == startNode) {
			if (separator != 0)
				result += separator;
		}
		startNode = startNode->GetNextNode();
	}

  return result;
}



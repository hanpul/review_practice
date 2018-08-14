// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	mData = data;
	mPrevNode = nullptr;
	mNextNode = nullptr;
  return;
}

char Node::GetData() {
  return mData;
}

Node* Node::GetPreviousNode() {
  return mPrevNode;
}

Node* Node::GetNextNode() {
  return mNextNode;
}

Node* Node::InsertPreviousNode(char data) {
	Node *newNode = new Node(data);
	Node *prevNode = mPrevNode;
	if (prevNode != nullptr) {
		prevNode->mNextNode = newNode;
		newNode->mPrevNode = prevNode;
	}

	mPrevNode = newNode;
	newNode->mNextNode = this;
  return newNode;
}

Node* Node::InsertNextNode(char data) {
	Node *newNode = new Node(data);
	Node *nextNode = mNextNode;
	if (nextNode != nullptr) {
		newNode->mNextNode = nextNode;
		nextNode->mPrevNode = newNode;
	}
	mNextNode = newNode;	
	newNode->mPrevNode = this;
  return newNode;
}

bool Node::ErasePreviousNode() {
	Node *prevNode = mPrevNode;
	if (prevNode == nullptr)
		return false;

	mPrevNode = prevNode->mPrevNode;
	if (mPrevNode != nullptr)
		mPrevNode->mNextNode = this;
	delete prevNode;

  return true;
}

bool Node::EraseNextNode() {
	Node *nextNode = mNextNode;
	if (nextNode == nullptr)
		return false;

	mNextNode = nextNode->mNextNode;

	if (mNextNode != nullptr)
		mNextNode->mPrevNode = this;
	delete nextNode;

  return true;
}

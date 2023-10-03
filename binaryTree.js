// Node class represents a single node in the binary tree
class Node {
    constructor(value) {
      this.value = value;
      this.left = null;
      this.right = null;
    }
  }
  
  // BinarySearchTree class represents the binary search tree
  class BinarySearchTree {
    constructor() {
      this.root = null;
    }
  
    // Function to insert a value into the binary search tree
    insert(value) {
      const newNode = new Node(value);
  
      if (!this.root) {
        this.root = newNode;
      } else {
        this.insertNode(this.root, newNode);
      }
    }
  
    // Helper function to recursively insert a value into the binary search tree
    insertNode(node, newNode) {
      if (newNode.value < node.value) {
        if (!node.left) {
          node.left = newNode;
        } else {
          this.insertNode(node.left, newNode);
        }
      } else {
        if (!node.right) {
          node.right = newNode;
        } else {
          this.insertNode(node.right, newNode);
        }
      }
    }
  
    // Function to search for a value within the binary search tree
    search(value) {
      return this.searchNode(this.root, value);
    }
  
    // Helper function to recursively search for a value within the binary search tree
    searchNode(node, value) {
      if (node === null) {
        return false;
      }
  
      if (value < node.value) {
        return this.searchNode(node.left, value);
      } else if (value > node.value) {
        return this.searchNode(node.right, value);
      } else {
        return true;
      }
    }
  }
  
const bst = new BinarySearchTree();

bst.insert(10);
bst.insert(5);
bst.insert(15);
bst.insert(3);
bst.insert(8);

console.log(bst.search(5)); // Output: true
console.log(bst.search(12)); // Output: false
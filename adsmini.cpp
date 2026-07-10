/*
 * ============================================================
 * E-Commerce Recommendation & Analytics System
 * Data Structures: Binary Search Tree (BST) + Graph (Bipartite)
 * Language: C++
 * Author: ADS Project
 * ============================================================
 *
 * BST FEATURES:
 * 1. Insert product into BST (ordered by price)
 * 2. Search product by name
 * 3. Display products Low->High (Inorder)
 * 4. Display products High->Low (Reverse Inorder)
 * 5. Delete product (Admin)
 * 6. Price range, budget, and category filters
 * 7. In-stock visibility and management
 *
 * GRAPH FEATURES:
 * 1. Bipartite graph: Users + Products as nodes, Purchase = edge
 * 2. Purchase product (adds edge + user history)
 * 3. Recommend products (Collaborative Filtering)
 * 4. Frequently Bought Together analysis
 * 5. Most popular product & Most active user analytics
 * ============================================================
 */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

// ============================================================
// 1. CONSTANTS & DATA STRUCTURES
// ============================================================

const int MAX_HISTORY = 100; // Maximum purchases a single user can have
const int MAX_USERS = 20; // Maximum distinct users tracked
const int MAX_PRODUCTS = 100; // Maximum unique products tracked in the graph
const int MAX_EDGES = 500; // Maximum total purchase transactions (edges)

// Product Node for the Binary Search Tree
struct Product {
    int id;
    string name;
    string category;
    double price;
    double rating; // 1.0 to 5.0
    bool inStock;

    Product* left; // Points to product with lower price
    Product* right; // Points to product with higher price

    // Constructor to easily initialize a Product node
    Product(int i, string n, string cat, double p, double r, bool s)
        : id(i), name(n), category(cat), price(p),
          rating(r), inStock(s), left(nullptr), right(nullptr) {}
};

// Simple User History Structure (Used for local tracking)
struct UserHistory {
    string username;
    string purchases[MAX_HISTORY];
    int count;

    UserHistory() : username(""), count(0) {}
};

// Graph Edge representing a bipartite connection: User -> Product
struct Edge {
    string username;
    string productName;
};

// ============================================================
// 2. GLOBAL STATE
// ============================================================
// Forward Declaration
Product* searchByName(Product* node, const string& name);
// BST Root pointer
Product* root = nullptr;          

// User History tracking
UserHistory users[MAX_USERS];             
int userCount = 0;               

// Global Bipartite Graph representation (Edge list)
Edge edges[MAX_EDGES];
int edgeCount = 0;

// Nodes representing distinct products in the graph
string graphProducts[MAX_PRODUCTS];
int graphProductCount = 0;

// Nodes representing distinct users in the graph
string graphUsers[MAX_USERS];
int graphUserCount = 0;

// ============================================================
// 3. INPUT VALIDATION HELPERS
// ============================================================

// Helper to remove leading and trailing whitespaces
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// Safely get a string, ensuring it is not completely empty
string getNonEmptyString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        input = trim(input);
        if (!input.empty()) return input;
        cout << "[Error] Input cannot be empty. Please try again.\n";
    }
}

// Safely read an integer, catching formatting errors and avoiding infinite loops
int getValidInt(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            size_t pos;
            long long temp = stoll(input, &pos);
            if (pos == input.length()) { // Entire string is valid integer
                return (int)temp;
            }
        } catch (...) {}
        cout << "[Error] Invalid input. Please enter a valid integer.\n";
    }
}

// Safely read a double-precision floating-point number
double getValidDouble(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            size_t pos;
            double value = stod(input, &pos);
            if (pos == input.length()) {
                return value;
            }
        } catch (...) {}
        cout << "[Error] Invalid input. Please enter a valid number.\n";
    }
}

// Prompt for and validate price (must not be negative)
double getValidPrice(const string& prompt) {
    double price;
    while (true) {
        price = getValidDouble(prompt);
        if (price >= 0.0) return price;
        cout << "[Error] Price cannot be negative. Please try again.\n";
    }
}

// Prompt for and validate rating (must be 1.0 to 5.0)
double getValidRating(const string& prompt) {
    double rating;
    while (true) {
        rating = getValidDouble(prompt);
        if (rating >= 1.0 && rating <= 5.0) return rating;
        cout << "[Error] Rating must be between 1.0 and 5.0. Please try again.\n";
    }
}

// Enforce yes/no input for robust toggles
bool getYesNoOption(const string& prompt) {
    while (true) {
        string input = getNonEmptyString(prompt);
        if (input == "y" || input == "Y") return true;
        if (input == "n" || input == "N") return false;
        cout << "[Error] Please enter 'y' or 'n'.\n";
    }
}

// ============================================================
// 4. UTILITY & FORMATTING FUNCTIONS
// ============================================================

// Cleanly prints product data within an ASCII box
void printProduct(Product* p) {
    if (!p) return;
    
    string t_id = to_string(p->id);
    
    // Format price and rating safely to strings
    stringstream ps; ps << fixed << setprecision(2) << "Rs." << p->price;
    string t_price = ps.str();
    
    stringstream rs; rs << fixed << setprecision(1) << p->rating << " / 5.0";
    string t_rating = rs.str();
    
    string t_stock = p->inStock ? "Yes" : "No";

    cout << " +---------------------------------------+\n";
    cout << " | ID : " << left << setw(26) << t_id << "|\n";
    cout << " | Name : " << left << setw(26) << p->name << "|\n";
    cout << " | Category : " << left << setw(26) << p->category << "|\n";
    cout << " | Price : " << left << setw(26) << t_price << "|\n";
    cout << " | Rating : " << left << setw(26) << t_rating << "|\n";
    cout << " | In Stock : " << left << setw(26) << t_stock << "|\n";
    cout << " +---------------------------------------+\n\n";
}

// Find User in the array, allocating a newly initialized one if needed
UserHistory* getUser(const string& username) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username)
            return &users[i];
    }
    if (userCount < MAX_USERS) {
        users[userCount].username = username;
        return &users[userCount++];
    }
    cout << "[Error] User limit reached. Cannot register new user history.\n";
    return nullptr;
}

// Generalized array lookup check
bool arrayContains(string arr[], int size, const string& val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

// ============================================================
// 5. GRAPH MODULE FUNCTIONS
// ============================================================

void ensureGraphUser(const string& username) {
    if (!arrayContains(graphUsers, graphUserCount, username)) {
        if (graphUserCount < MAX_USERS)
            graphUsers[graphUserCount++] = username;
    }
}

void ensureGraphProduct(const string& productName) {
    if (!arrayContains(graphProducts, graphProductCount, productName)) {
        if (graphProductCount < MAX_PRODUCTS)
            graphProducts[graphProductCount++] = productName;
    }
}

// Register a link between user and product indicating a purchase
void addGraphEdge(const string& username, const string& productName) {
    if (edgeCount >= MAX_EDGES) {
        cout << "[Warning] Graph edge limit reached. Cannot record new edge.\n";
        return;
    }
    edges[edgeCount].username = username;
    edges[edgeCount].productName = productName;
    edgeCount++;

    ensureGraphUser(username);
    ensureGraphProduct(productName);
}

// ------------------------------------------------------------
// GRAPH ANALYTIC: Collaborative Filtering Recommendations
// Path Logic: User -> Bought Products -> Other Users -> Their Products
// ------------------------------------------------------------
void bfsRecommendationTraversal(const string& username, string recommended[], int &recCount) {
    queue<string> q;
    set<string> visitedUsers;
    set<string> visitedProducts;

    string myProducts[MAX_HISTORY];
    int myCount = 0;

    for (int i = 0; i < edgeCount; i++) {
        if (edges[i].username == username) {
            if (myCount < MAX_HISTORY) {
                myProducts[myCount++] = edges[i].productName;
            }
            q.push(edges[i].productName);
            visitedProducts.insert(edges[i].productName);
        }
    }

    while (!q.empty()) {
        string currentProduct = q.front();
        q.pop();

        for (int i = 0; i < edgeCount; i++) {
            if (edges[i].productName == currentProduct) {
                string otherUser = edges[i].username;

                if (visitedUsers.count(otherUser)) continue;
                visitedUsers.insert(otherUser);

                for (int j = 0; j < edgeCount; j++) {
                    if (edges[j].username == otherUser) {
                        string candidate = edges[j].productName;

                        if (arrayContains(myProducts, myCount, candidate)) continue;
                        if (arrayContains(recommended, recCount, candidate)) continue;

                        if (recCount < MAX_PRODUCTS) {
                            recommended[recCount++] = candidate;
                        }

                        if (!visitedProducts.count(candidate)) {
                            visitedProducts.insert(candidate);
                            q.push(candidate);
                        }
                    }
                }
            }
        }
    }
}

void recommendProducts(const string& username) {
    cout << "\n=== Recommendations for [" << username << "] ===\n";

    // Step 1: Check if the user has any purchase history
    int myCount = 0;
    for (int i = 0; i < edgeCount; i++) {
        if (edges[i].username == username) {
            myCount++;
        }
    }

    if (myCount == 0) {
        cout << "[Info] No purchase history found. Buy something first to get recommendations!\n\n";
        return;
    }

    string recommended[MAX_PRODUCTS];
    int recCount = 0;

    // Use BFS logic to generate recommendations
    bfsRecommendationTraversal(username, recommended, recCount);

    if (recCount == 0) {
        cout << "[Info] No new recommendations found for you.\n\n";
        return;
    }

    cout << " Based on your purchase history, you might also like:\n\n";
    for (int i = 0; i < recCount; i++) {
        // We only possess names in our array, request full details from BST root
        // We ensure we can call it properly:
       Product* p = searchByName(root, recommended[i]);
        if (p != nullptr) {
            cout << " [" << (i + 1) << "]\n";
            printProduct(p);
        }
    }
}

// ------------------------------------------------------------
// GRAPH ANALYTIC: Frequently Bought Together
// Logic: Find users who bought X, fetch what else they bought.
// ------------------------------------------------------------
void frequentlyBoughtTogether(const string& productName) {
    cout << "\n=== Frequently Bought Together with '" << productName << "' ===\n";

    string buyers[MAX_USERS];
    int buyerCount = 0;

    // Step 1: Find all users who explicitly bought this product
    for (int i = 0; i < edgeCount; i++) {
        if (edges[i].productName == productName) {
            if (!arrayContains(buyers, buyerCount, edges[i].username)) {
                if (buyerCount < MAX_USERS) buyers[buyerCount++] = edges[i].username;
            }
        }
    }

    if (buyerCount == 0) {
        cout << "[Info] No purchase data yet for '" << productName << "'.\n\n";
        return;
    }

    string related[MAX_PRODUCTS];
    int relCount = 0;

    // Step 2: Grab all OTHER items purchased by these specific buyers
    for (int b = 0; b < buyerCount; b++) {
        for (int e = 0; e < edgeCount; e++) {
            if (edges[e].username == buyers[b] && edges[e].productName != productName) {
                if (!arrayContains(related, relCount, edges[e].productName)) {
                    if (relCount < MAX_PRODUCTS) related[relCount++] = edges[e].productName;
                }
            }
        }
    }

    if (relCount == 0) {
        cout << "[Info] No co-purchased products found.\n\n";
        return;
    }

    // Step 3: Print their details
    for (int i = 0; i < relCount; i++) {
        Product* p = searchByName(root, related[i]);
        if (p != nullptr) {
            cout << " [" << (i + 1) << "]\n";
            printProduct(p);
        }
    }
}

// ------------------------------------------------------------
// GRAPH ANALYTIC: Most Popular Product (Max Degree Centrality)
// ------------------------------------------------------------
void mostPopularProduct() {
    cout << "\n=== Most Popular Product ===\n";

    if (graphProductCount == 0) {
        cout << "[Info] No purchase data available.\n\n";
        return;
    }

    string bestProduct = "";
    int bestCount = 0;

    // Compute degree per product node
    for (int gp = 0; gp < graphProductCount; gp++) {
        int count = 0;
        for (int e = 0; e < edgeCount; e++) {
            if (edges[e].productName == graphProducts[gp]) count++;
        }
        if (count > bestCount) {
            bestCount = count;
            bestProduct = graphProducts[gp];
        }
    }

    cout << " Winner: " << bestProduct << " (" << bestCount << " purchases)\n\n";
    Product* p = searchByName(root, bestProduct);
    if (p != nullptr) printProduct(p);
}

// ------------------------------------------------------------
// GRAPH ANALYTIC: Most Active User (Max Out-Degree Centrality)
// ------------------------------------------------------------
void mostActiveUser() {
    cout << "\n=== Most Active User ===\n";

    if (graphUserCount == 0) {
        cout << "[Info] No user purchase data available.\n\n";
        return;
    }

    string bestUser = "";
    int bestCount = 0;

    // Compute out-degree per user node
    for (int gu = 0; gu < graphUserCount; gu++) {
        int count = 0;
        for (int e = 0; e < edgeCount; e++) {
            if (edges[e].username == graphUsers[gu]) count++;
        }
        if (count > bestCount) {
            bestCount = count;
            bestUser = graphUsers[gu];
        }
    }

    cout << " Most Active User: " << bestUser << " (" << bestCount << " purchases)\n\n";
}


// ============================================================
// 6. BST MODULE FUNCTIONS
// ============================================================

// Standard BST Insertion (Ordered structurally by Price constraint)
Product* insertProduct(Product* node, int id, string name, string category, double price, double rating, bool inStock) {
    if (node == nullptr) {
        return new Product(id, name, category, price, rating, inStock);
    }
    // Duplicate prices cascade to the right subtree
    if (price < node->price) {
        node->left = insertProduct(node->left, id, name, category, price, rating, inStock);
    } else {
        node->right = insertProduct(node->right, id, name, category, price, rating, inStock);
    }
    return node;
}

// Full Tree In-Order Scan lookup by string
// Required full O(n) traversal since BST is natively indexed by Price, not Name
Product* searchByName(Product* node, const string& name) {
    if (node == nullptr) return nullptr;

    if (node->name == name) return node;

    Product* found = searchByName(node->left, name);
    if (found != nullptr) return found;

    return searchByName(node->right, name);
}

// In-Order Traversal yields ascending prices dynamically
void displayLowToHigh(Product* node) {
    if (node == nullptr) return;
    displayLowToHigh(node->left);
    printProduct(node);
    displayLowToHigh(node->right);
}

// Reverse In-Order Traversal yields descending prices dynamically
void displayHighToLow(Product* node) {
    if (node == nullptr) return;
    displayHighToLow(node->right);
    printProduct(node);
    displayHighToLow(node->left);
}

// Utility for BST Node Removal Successor Lookup
Product* findMin(Product* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Delete product securely adapting to 3 structural deletion cases
Product* deleteProduct(Product* node, const string& name, bool& deleted) {
    if (node == nullptr) return nullptr;  

    node->left = deleteProduct(node->left, name, deleted);
    node->right = deleteProduct(node->right, name, deleted);

    // Act directly once tree bottom-up traversal finds the identity
    if (node->name == name && !deleted) {
        deleted = true;

        // Case 1: Leaf node 
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Case 2a: Only right child
        if (node->left == nullptr) {
            Product* temp = node->right;
            delete node;
            return temp;
        }
        // Case 2b: Only left child
        if (node->right == nullptr) {
            Product* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Standard heavy removal via in-order Successor substitution
        Product* successor = findMin(node->right);
        node->id = successor->id;
        node->name = successor->name;
        node->category = successor->category;
        node->price = successor->price;
        node->rating = successor->rating;
        node->inStock = successor->inStock;
        
        bool dummy = false;
        node->right = deleteProduct(node->right, successor->name, dummy);
    }
    return node;
}

// BST Pruning Traversal based directly on mathematical boundaries
void filterByPriceRange(Product* node, double minPrice, double maxPrice) {
    if (node == nullptr) return;

    if (node->price > minPrice) filterByPriceRange(node->left, minPrice, maxPrice);
    if (node->price >= minPrice && node->price <= maxPrice) printProduct(node);
    if (node->price < maxPrice) filterByPriceRange(node->right, minPrice, maxPrice);
}

void filterByBudget(Product* node, double budget) {
    if (node == nullptr) return;

    filterByBudget(node->left, budget);
    if (node->price <= budget) printProduct(node);
    if (node->price < budget) filterByBudget(node->right, budget);
}

// Global naive scan filter bounds bypassing tree indexing logic
void filterByCategory(Product* node, const string& category) {
    if (node == nullptr) return;
    filterByCategory(node->left, category);
    if (node->category == category) printProduct(node);
    filterByCategory(node->right, category);
}

// Basic status property traversal
void displayInStockOnly(Product* node) {
    if (node == nullptr) return;
    displayInStockOnly(node->left);
    if (node->inStock) printProduct(node);
    displayInStockOnly(node->right);
}

// In-place node mutation (Admin utility)
void markStockStatus(const string& productName, bool newStatus) {
    if (root == nullptr) {
        cout << "[Error] No products in system.\n";
        return;
    }

    Product* p = searchByName(root, productName);
    if (p == nullptr) {
        cout << "[Error] Product '" << productName << "' not found.\n";
        return;
    }

    p->inStock = newStatus;
    cout << "[Success] '" << productName << "' marked as "
         << (newStatus ? "IN STOCK" : "OUT OF STOCK") << ".\n";
}

// ============================================================
// 7. USER SYSTEM OPERATION FUNCTIONS
// ============================================================

void purchaseProduct(const string& username, const string& productName) {
    if (root == nullptr) {
        cout << "[Error] No products available to purchase.\n";
        return;
    }

    Product* p = searchByName(root, productName);
    if (p == nullptr) {
        cout << "[Error] Product '" << productName << "' not found.\n";
        return;
    }
    if (!p->inStock) {
        cout << "[Error] Sorry, '" << productName << "' is currently out of stock.\n";
        return;
    }

    UserHistory* user = getUser(username);
    if (user == nullptr) return; 

    if (user->count >= MAX_HISTORY) {
        cout << "[Error] Purchase history limit full for user: " << username << ".\n";
        return;
    }

    user->purchases[user->count++] = productName;
    addGraphEdge(username, productName);

    cout << "\n[Success] '" << productName << "' purchased successfully by " << username << "!\n";
    cout << " Price paid: Rs." << fixed << setprecision(2) << p->price << "\n\n";
}

void viewPurchaseHistory(const string& username) {
    UserHistory* user = getUser(username);
    if (user == nullptr) return;

    if (user->count == 0) {
        cout << "[Info] No purchase history for user: " << username << "\n";
        return;
    }

    cout << "\n=== Purchase History for [" << username << "] ===\n";
    for (int i = 0; i < user->count; i++) {
        cout << " " << (i + 1) << ". " << user->purchases[i] << "\n";
    }
    cout << "Total purchases: " << user->count << "\n\n";
}

// ============================================================
// 8. SYSTEM INITIALIZATION
// ============================================================

void loadSampleData() {
    root = insertProduct(root, 101, "Wireless Earbuds", "Electronics", 1499.0, 4.2, true);
    root = insertProduct(root, 102, "Running Shoes", "Footwear", 2999.0, 4.5, true);
    root = insertProduct(root, 103, "Yoga Mat", "Sports", 799.0, 4.0, true);
    root = insertProduct(root, 104, "Smart Watch", "Electronics", 5999.0, 4.7, true);
    root = insertProduct(root, 105, "Backpack", "Bags", 1299.0, 3.8, false);
    root = insertProduct(root, 106, "Water Bottle", "Sports", 399.0, 4.1, true);
    root = insertProduct(root, 107, "Bluetooth Speaker", "Electronics", 3499.0, 4.3, true);
    root = insertProduct(root, 108, "Laptop Stand", "Electronics", 1899.0, 4.0, true);

    purchaseProduct("Alice", "Wireless Earbuds");
    purchaseProduct("Alice", "Yoga Mat");
    purchaseProduct("Bob", "Wireless Earbuds");
    purchaseProduct("Bob", "Running Shoes");
    purchaseProduct("Bob", "Water Bottle");
    purchaseProduct("Carol", "Smart Watch");
    purchaseProduct("Carol", "Bluetooth Speaker");
    purchaseProduct("Carol", "Running Shoes");
    purchaseProduct("Dave", "Yoga Mat");
    purchaseProduct("Dave", "Water Bottle");

    cout << "\n============================================\n";
    cout << " Sample data loaded seamlessly context!\n";
    cout << " 8 products + initial purchase network set.\n";
    cout << "============================================\n\n";
}

// ============================================================
// 9. MENU SYSTEM
// ============================================================

void adminMenu() {
    int choice;
    do {
        cout << "\n============================================\n";
        cout << " ADMIN MENU \n";
        cout << "============================================\n";
        cout << " 1. Add Product \n";
        cout << " 2. Delete Product \n";
        cout << " 3. Mark Stock Status \n";
        cout << " 4. Display All (Low->High) \n";
        cout << " 5. Display All (High->Low) \n";
        cout << " 0. Logout \n";
        cout << "============================================\n";
        choice = getValidInt("Choice: ");

        if (choice == 1) {
            int id = getValidInt("Enter Product ID : ");
            string name = getNonEmptyString("Enter Product Name : ");
            string category = getNonEmptyString("Enter Category : ");
            double price = getValidPrice("Enter Price (Rs.) : ");
            double rating = getValidRating("Enter Rating (1-5) : ");
            bool inStock = getYesNoOption("In Stock? (y/n) : ");

            root = insertProduct(root, id, name, category, price, rating, inStock);
            ensureGraphProduct(name);
            cout << "\n[Success] Product '" << name << "' permanently deployed.\n";
        }
        else if (choice == 2) {
            string name = getNonEmptyString("Enter product name to delete: ");
            bool deleted = false;
            root = deleteProduct(root, name, deleted);
            if (deleted) cout << "\n[Success] '" << name << "' was completely removed.\n";
            else cout << "\n[Error] Product '" << name << "' was not found in systems.\n";
        }
        else if (choice == 3) {
            string name = getNonEmptyString("Enter product name : ");
            bool newStatus = getYesNoOption("Mark as in-stock? (y/n) : ");
            markStockStatus(name, newStatus);
        }
        else if (choice == 4) {
            if (root == nullptr) { cout << "[Info] No products in system.\n"; }
            else {
                cout << "\n=== Products (Low to High Price) ===\n";
                displayLowToHigh(root);
            }
        }
        else if (choice == 5) {
            if (root == nullptr) { cout << "[Info] No products in system.\n"; }
            else {
                cout << "\n=== Products (High to Low Price) ===\n";
                displayHighToLow(root);
            }
        }
        else if (choice != 0) {
            cout << "[Error] Invalid specific action.\n";
        }

    } while (choice != 0);

    cout << "\n[Admin securely logged out]\n";
}

void userMenu(const string& username) {
    int choice;
    do {
        cout << "\n============================================\n";
        cout << " USER MENU: [" << username << "]\n";
        cout << "============================================\n";
        cout << " 1. Search Product by Name \n";
        cout << " 2. View All Products (Low->High) \n";
        cout << " 3. View All Products (High->Low) \n";
        cout << " 4. Filter by Price Range \n";
        cout << " 5. Filter by Budget \n";
        cout << " 6. Filter by Category \n";
        cout << " 7. Show In-Stock Products Only \n";
        cout << " 8. Purchase a Product \n";
        cout << " 9. View Purchase History \n";
        cout << " 10. Get Smart Recommendations \n";
        cout << " 11. Frequently Bought Together Analyics \n";
        cout << " 12. Most Popular Product Platform-Wide \n";
        cout << " 13. Most Active User Across Platform \n";
        cout << " 0. Logout User Instance \n";
        cout << "============================================\n";
        choice = getValidInt("Choice: ");

        if (choice == 1) {
            string name = getNonEmptyString("Enter product name to search: ");
            Product* p = searchByName(root, name);
            if (p == nullptr) cout << "\n[Error] Product '" << name << "' could not be found.\n";
            else {
                cout << "\n[Product Result Verified]\n";
                printProduct(p);
            }
        }
        else if (choice == 2) {
            if (root == nullptr) cout << "[Info] Ecosystem empty.\n";
            else { cout << "\n=== All Products (Low to High Price) ===\n"; displayLowToHigh(root); }
        }
        else if (choice == 3) {
            if (root == nullptr) cout << "[Info] Ecosystem empty.\n";
            else { cout << "\n=== All Products (High to Low Price) ===\n"; displayHighToLow(root); }
        }
        else if (choice == 4) {
            double minP = getValidPrice("Enter minimum price (Rs.): ");
            double maxP = getValidPrice("Enter maximum price (Rs.): ");
            if (minP > maxP) {
                cout << "[Error] Minimum price cannot be legally greater than maximum.\n";
            } else {
                cout << "\n=== Products in Range Rs." << minP << " - Rs." << maxP << " ===\n";
                filterByPriceRange(root, minP, maxP);
            }
        }
        else if (choice == 5) {
            double budget = getValidPrice("Enter maximum spending cap (Rs.): ");
            cout << "\n=== Products under strict Budget Rs." << budget << " ===\n";
            filterByBudget(root, budget);
        }
        else if (choice == 6) {
            string cat = getNonEmptyString("Enter category (ex: Electronics, Sports, Bags): ");
            cout << "\n=== Products categorized internally as: " << cat << " ===\n";
            filterByCategory(root, cat);
        }
        else if (choice == 7) {
            cout << "\n=== Actively Stocked Physical Products ===\n";
            displayInStockOnly(root);
        }
        else if (choice == 8) {
            string name = getNonEmptyString("Enter specific product name to initiate purchase: ");
            purchaseProduct(username, name);
        }
        else if (choice == 9) viewPurchaseHistory(username);
        else if (choice == 10) recommendProducts(username);
        else if (choice == 11) {
            string name = getNonEmptyString("Enter root product name for overlap analysis: ");
            frequentlyBoughtTogether(name);
        }
        else if (choice == 12) mostPopularProduct();
        else if (choice == 13) mostActiveUser();
        else if (choice != 0) { cout << "[Error] Incorrect selection ID.\n"; }

    } while (choice != 0);

    cout << "\n[User " << username << " successfully signed off]\n";
}

// ============================================================
// 10. MAIN ENTRY POINT
// ============================================================

int main() {
    cout << "============================================\n";
    cout << " E-Commerce Recommendation & Analytics\n";
    cout << " System utilizing Structural Trees & Graphs\n";
    cout << "============================================\n\n";

    // Standard pre-initialization flow load
    loadSampleData();

    int mainChoice;
    do {
        cout << "\n============================================\n";
        cout << " MAIN MENU \n";
        cout << "============================================\n";
        cout << " 1. Login safely as Supervisor (Admin) \n";
        cout << " 2. Login safely as Client (User) \n";
        cout << " 0. Process Exit Operation \n";
        cout << "============================================\n";
        mainChoice = getValidInt("Choice: ");

        if (mainChoice == 1) {
            string pwd = getNonEmptyString("Enter secure administrator code: ");
            if (pwd == "admin123") {
                cout << "\n[Access Granted] Verified Admin Status!\n";
                adminMenu();
            } else {
                cout << "\n[Access Denied] Authentication rejected.\n";
            }
        }
        else if (mainChoice == 2) {
            string uname = getNonEmptyString("Sign in identity (Username): ");
            cout << "\n[Welcome] Validated. Hello, " << uname << "!\n";
            userMenu(uname);
        }
        else if (mainChoice != 0) {
            cout << "\n[Error] Invalid choice pattern. Try again.\n";
        }

    } while (mainChoice != 0);

    cout << "\nTerminal execution successfully closed. Goodbye!\n";
    return 0;
}

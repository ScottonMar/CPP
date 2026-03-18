#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// ----------------------
// Transaction Definition
// ----------------------
class Transaction {
public:
    string accountId;
    double amount;

    Transaction(string acc, double amt)
        : accountId(acc), amount(amt) {}
};

// -----------------------------
// TransactionProcessor Class
// -----------------------------
class TransactionProcessor {
private:
    vector<unique_ptr<Transaction>> database;

public:
    // Process a single transaction
    void processTransaction() {
        string accountId;
        double amount;

        cout << "Enter Account ID: ";
        cin >> accountId;

        cout << "Enter Amount: ";
        cin >> amount;

        // 1. Allocate on heap
        auto tx = make_unique<Transaction>(accountId, amount);
        Transaction* ptr = tx.get();   // pointer for processing

        // 2. Processing through pointer
        normalizeAccountId(ptr);
        roundAmount(ptr);

        // 3. Validation
        if (!validate(ptr)) {
            cout << "❌ Transaction Rejected\n\n";
            return; // do NOT store
        }

        // 4. Store in database
        cout << "✅ Transaction Accepted\n";
        cout << "   Memory Address: " << ptr << "\n\n";
        database.push_back(std::move(tx));
    }

    // Normalize accountId (uppercase)
    void normalizeAccountId(Transaction* tx) {
        for (char& c : tx->accountId) {
            c = toupper(c);
        }
    }

    // Round amount to 2 decimals
    void roundAmount(Transaction* tx) {
        tx->amount = static_cast<int>(tx->amount * 100 + 0.5) / 100.0;
    }

    // Validation rules
    bool validate(Transaction* tx) {
        if (tx->amount <= 0) {
            cout << "Reason: Amount must be greater than 0\n";
            return false;
        }
        if (tx->accountId.empty()) {
            cout << "Reason: Account ID cannot be empty\n";
            return false;
        }
        return true;
    }

    // Print stored transactions
    void printDatabase() {
        cout << "----- Stored Transactions -----\n";
        for (auto& tx : database) {
            cout << "Account: " << tx->accountId
                 << " | Amount: " << tx->amount
                 << " | Address: " << tx.get() << "\n";
        }
        cout << "--------------------------------\n";
    }
};

// -----------------------------
// Main Program
// -----------------------------
int main() {
    TransactionProcessor processor;

    cout << "Mini-TPS Transaction Processor\n\n";

    // Process multiple transactions
    processor.processTransaction();  // try one that gets rejected
    processor.processTransaction();  // try one that gets accepted

    processor.printDatabase();

    return 0;
}

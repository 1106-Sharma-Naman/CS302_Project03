// NAMAN SHARMA
// driver.cpp
// CS 302 – Project 3: Music Library (Binary Search Tree)

#include "Song.h"
#include "MusicLibrary.h"
#include "BinaryTreeInterface.h"
#include "NotFoundException.h"
#include <iostream>
#include <string>

using namespace std;

// --------------------------------------------------
// Visit function passed to all three traversal methods.
// Called once per node in traversal order.
// Uses Song::operator<< to display each song.
// --------------------------------------------------
void displaySong(Song& song)
{
    cout << "  " << song << endl;
}

// Prints a labeled section divider for readable output
void printSection(const string& label)
{
    cout << endl;
    cout << "========================================" << endl;
    cout << "  " << label << endl;
    cout << "========================================" << endl;
}

int main()
{
    MusicLibrary library;

    // --------------------------------------------------
    // CHECK: isEmpty() on empty library
    // --------------------------------------------------
    printSection("1. Empty Library Check");
    cout << "isEmpty():          " << (library.isEmpty() ? "true" : "false") << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << "getHeight():        " << library.getHeight() << endl;

    // --------------------------------------------------
    // CHECK: Add at least 8 songs
    // --------------------------------------------------
    printSection("2. Adding Songs (at least 8)");

    // Chosen order:
    // M root
    // G left, T right
    // D under G, J under G
    // P under T, W under T
    // B under D
    //
    // Before removals:
    // - B is leaf
    // - D has one child
    // - G has two children

    library.add(Song("Midnights", "Taylor Swift", 2022));
    library.add(Song("Ghost", "Justin Bieber", 2021));
    library.add(Song("Thunder", "Imagine Dragons", 2017));
    library.add(Song("Demons", "Imagine Dragons", 2013));
    library.add(Song("Levitating", "Dua Lipa", 2020));
    library.add(Song("Perfect", "Ed Sheeran", 2017));
    library.add(Song("Yellow", "Coldplay", 2000));
    library.add(Song("Bad Guy", "Billie Eilish", 2019));

    cout << "Songs added." << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;

    // --------------------------------------------------
    // CHECK: Display using all three traversals
    // CHECK: Inorder must produce alphabetical order by title
    // --------------------------------------------------
    printSection("3. Inorder Traversal (alphabetical by title)");
    library.inorderTraverse(displaySong);

    printSection("4. Preorder Traversal (Root -> Left -> Right)");
    library.preorderTraverse(displaySong);

    printSection("5. Postorder Traversal (Left -> Right -> Root)");
    library.postorderTraverse(displaySong);

    // --------------------------------------------------
    // CHECK: isBalanced(), getHeight(), getNumberOfNodes()
    // --------------------------------------------------
    printSection("6. Balance Check");
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << "getHeight():        " << library.getHeight() << endl;
    cout << "isBalanced():       " << (library.isBalanced() ? "true" : "false") << endl;
    cout << endl;
    cout << "For a balanced tree of n nodes, expected height = floor(log2(n)) + 1" << endl;

    // --------------------------------------------------
    // CHECK: contains() — song that EXISTS
    // --------------------------------------------------
    printSection("7. Search — Song That Exists");
    Song existingSong("Perfect", "", 0);
    cout << "Searching for \"" << existingSong.getTitle() << "\"..." << endl;
    cout << "contains(): " << (library.contains(existingSong) ? "true" : "false") << endl;

    // --------------------------------------------------
    // CHECK: contains() — song that DOES NOT EXIST
    // --------------------------------------------------
    printSection("8. Search — Song That Does Not Exist");
    Song missingSong("Not In Library", "", 0);
    cout << "Searching for \"" << missingSong.getTitle() << "\"..." << endl;
    cout << "contains(): " << (library.contains(missingSong) ? "true" : "false") << endl;

    // --------------------------------------------------
    // CHECK: getEntry() — song that EXISTS
    // --------------------------------------------------
    printSection("9. getEntry() — Song That Exists");
    try
    {
        Song query("Thunder", "", 0);
        Song found = library.getEntry(query);
        cout << "getEntry() found: " << found << endl;
    }
    catch (const NotFoundException& e)
    {
        cout << "NotFoundException caught: " << e.what() << endl;
    }

    // --------------------------------------------------
    // CHECK: getEntry() — song that DOES NOT EXIST (NotFoundException)
    // --------------------------------------------------
    printSection("10. getEntry() — Song That Does Not Exist");
    try
    {
        Song badQuery("Not In Library", "", 0);
        Song found = library.getEntry(badQuery);
        cout << "getEntry() found: " << found << endl;
    }
    catch (const NotFoundException& e)
    {
        cout << "NotFoundException caught (expected): " << e.what() << endl;
    }

    // --------------------------------------------------
    // CHECK: Remove a LEAF node
    // --------------------------------------------------
    printSection("11. Remove — Leaf Node");
    Song leafSong("Bad Guy", "", 0);
    cout << "Removing \"" << leafSong.getTitle() << "\" (leaf)..." << endl;
    cout << "remove() returned: " << (library.remove(leafSong) ? "true" : "false") << endl;
    cout << "contains() after:  " << (library.contains(leafSong) ? "true" : "false") << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << endl << "Inorder after removal:" << endl;
    library.inorderTraverse(displaySong);

    // --------------------------------------------------
    // CHECK: Remove a node with ONE CHILD
    // --------------------------------------------------
    printSection("12. Remove — Node With One Child");
    Song oneChildSong("Demons", "", 0);
    cout << "Removing \"" << oneChildSong.getTitle() << "\" (one child)..." << endl;
    cout << "remove() returned: " << (library.remove(oneChildSong) ? "true" : "false") << endl;
    cout << "contains() after:  " << (library.contains(oneChildSong) ? "true" : "false") << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << endl << "Inorder after removal:" << endl;
    library.inorderTraverse(displaySong);

    // --------------------------------------------------
    // CHECK: Remove a node with TWO CHILDREN
    // --------------------------------------------------
    printSection("13. Remove — Node With Two Children");
    Song twoChildSong("Ghost", "", 0);
    cout << "Removing \"" << twoChildSong.getTitle() << "\" (two children)..." << endl;
    cout << "remove() returned: " << (library.remove(twoChildSong) ? "true" : "false") << endl;
    cout << "contains() after:  " << (library.contains(twoChildSong) ? "true" : "false") << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << endl << "Inorder after removal:" << endl;
    library.inorderTraverse(displaySong);

    // --------------------------------------------------
    // CHECK: remove() on a title that DOES NOT EXIST
    // --------------------------------------------------
    printSection("14. Remove — Non-Existent Song (safe handling)");
    Song notExist("Not In Library", "", 0);
    cout << "Removing \"" << notExist.getTitle() << "\" (not in library)..." << endl;
    cout << "remove() returned: " << (library.remove(notExist) ? "true" : "false") << endl;
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;

    // --------------------------------------------------
    // CHECK: Final state — getNumberOfNodes() and isEmpty()
    // --------------------------------------------------
    printSection("15. Final State");
    cout << "getNumberOfNodes(): " << library.getNumberOfNodes() << endl;
    cout << "getHeight():        " << library.getHeight() << endl;
    cout << "isEmpty():          " << (library.isEmpty() ? "true" : "false") << endl;
    cout << endl << "Final inorder traversal:" << endl;
    library.inorderTraverse(displaySong);

    cout << endl << "========================================" << endl;
    cout << "  All checklist items demonstrated." << endl;
    cout << "========================================" << endl;

    return 0;
}
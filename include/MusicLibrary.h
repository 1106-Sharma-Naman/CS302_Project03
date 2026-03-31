#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include "BinaryTreeInterface.h"
#include "Song.h"
#include "BST.h"

/*
   MusicLibrary is the public class for the project.
   It uses BST<Song> internally.
*/
class MusicLibrary : public BinaryTreeInterface<Song>
{
private:
    BST<Song> songTree;

public:
    MusicLibrary();
    virtual ~MusicLibrary();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;

    bool add(const Song& newData);
    bool remove(const Song& data);
    void clear();

    Song getEntry(const Song& anEntry) const;
    bool contains(const Song& anEntry) const;

    void preorderTraverse(void visit(Song&)) const;
    void inorderTraverse(void visit(Song&)) const;
    void postorderTraverse(void visit(Song&)) const;

    bool isBalanced() const;
};

#endif
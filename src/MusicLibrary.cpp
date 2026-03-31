#include "../include/MusicLibrary.h"

MusicLibrary::MusicLibrary()
{
}

MusicLibrary::~MusicLibrary()
{
    clear();
}

bool MusicLibrary::isEmpty() const
{
    return songTree.isEmpty();
}

int MusicLibrary::getHeight() const
{
    return songTree.getHeight();
}

int MusicLibrary::getNumberOfNodes() const
{
    return songTree.getNumberOfNodes();
}

bool MusicLibrary::add(const Song& newData)
{
    return songTree.add(newData);
}

bool MusicLibrary::remove(const Song& data)
{
    return songTree.remove(data);
}

void MusicLibrary::clear()
{
    songTree.clear();
}

Song MusicLibrary::getEntry(const Song& anEntry) const
{
    return songTree.getEntry(anEntry);
}

bool MusicLibrary::contains(const Song& anEntry) const
{
    return songTree.contains(anEntry);
}

void MusicLibrary::preorderTraverse(void visit(Song&)) const
{
    songTree.preorderTraverse(visit);
}

void MusicLibrary::inorderTraverse(void visit(Song&)) const
{
    songTree.inorderTraverse(visit);
}

void MusicLibrary::postorderTraverse(void visit(Song&)) const
{
    songTree.postorderTraverse(visit);
}

bool MusicLibrary::isBalanced() const
{
    return songTree.isBalanced();
}
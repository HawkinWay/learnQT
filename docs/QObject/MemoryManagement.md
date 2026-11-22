# Memory Management

In this section, we explore the built-in memory management system of QObject. Forgetting to delete dynamically allocated objects leads to memory leaks, while deleting objects that are still in use causes crashes. Qt provides a solution through its parent-child hierarchy, which automatically handles deletion of related objects.

Consider a dialog box with buttons, labels, and input fields. When the user closes the dialog, all those components need to be cleaned up. With Qt's parent-child system, you simply delete the dialog and all its children are automatically deleted along with it.

By the end of this section, you will be able to create parent-child hierarchies between QObjects, understand how automatic deletion works, and avoid common memory management pitfalls.

## Exploring the Parent-Child Hierarchy

All QObjects have a built-in system for managing a parent-child hierarchy. This parent-child hierarchy is intended to help with memory management. When a QObject is created with a parent, the parent takes ownership over the child, meaning when the parent is deleted all its children are deleted as well. This means developers don't need to manually delete QObjects if their parent is properly deleted.

For example, if an application has a temporary dialog box that opens and each component in the dialog box is a child of the dialog box itself, then when the dialog box is deleted, all the components within the dialog will be deleted along with it. In general, this helps to prevent memory leaks by ensuring that all objects of an application are dynamically deleted when they are no longer needed.

QObjects can be created with a parent, by passing a parent object to its constructor, or can have a parent assigned after its creation using the setParent()(opens in a new tab) function. The list of child objects of any QObject can also be obtained at runtime by using the children()(opens in a new tab) function.

Below shows a brief example where five QObjects are created: one "grandparent", one "parent", and three "children". These are each created with a parent, then the grandparent is deleted:

```cpp
MyQObject *grandParent = new MyQObject("Grand parent");

MyQObject *parent = new MyQObject("Parent", grandParent);

MyQObject *child1 = new MyQObject("Child 1", parent);
MyQObject *child2 = new MyQObject("Child 2", parent);
MyQObject *child3 = new MyQObject("Child 3");
child3->setParent(parent);

delete grandParent;
```

```txt
"Grand parent" created
"Parent" created
"Child 1" created
"Child 2" created
"Child 3" created
"Grand parent" destroyed
"Parent" destroyed
"Child 1" destroyed
"Child 2" destroyed
"Child 3" destroyed
```

When grandparent is deleted, the output shows that all five objects are destroyed: grandparent, parent, child1, child2, and child3. Even though we only explicitly deleted grandparent, each object that had either grandparent or parent as a parent was deleted as well. This demonstrates the memory management system of QObjects, where when a parent object is deleted, all the children are deleted as well, preventing the need to manually delete each object.

If we had not called setParent() on child3, it would not have been deleted, resulting in a memory leak. Any QObject created without a parent must either be manually deleted or have a parent assigned using setParent().
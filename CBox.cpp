int main(void)
{
    CBox myBox = 5
    Cbox *ptr1;
    Cbox *ptr2;
    
    ShowArea(&myBox);
    
    ptr1 = new CBox;
    ShowArea(ptr1);
    
    ptr2 = new CDbox(7);
    ShowArea(ptr2);
    delete ptr1;
    delete ptr2;
    
    return 0;
}

int main(void)
{
    //automatic (stack) array
    CBox arrayOne [3};
    ShowArea(arrayOne, 3);
    
    // dynamic (heap) array
    CBox *arrayPtr = new Cbox[5];
    ShowArea(arrayPtr,5);
    delete [] arrayPtr;
    
    // this is how to call the conversion constructor for an array
    CBox arrayTwo[3] = {CBox(2), CBox(3), CBox(3)}
}
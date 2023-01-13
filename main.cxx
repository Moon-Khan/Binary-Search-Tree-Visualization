#include<iostream>
#include"graphics.h"
#include<string>


using namespace std;

//node indexes
const int x = 600;
const int y = 180;


class BST_node {
public:
    int BST_data;
    BST_node* BST_left;
    BST_node* BST_right;


    //Constructor
    BST_node()
    {
        BST_data = 0;
        BST_left = BST_right = NULL;
    }
};

class BST {
public:

    //BST_node root
    BST_node* BST_root;

    BST()
    {
        BST_root = NULL;
    }

    //BST Insertion
    BST_node* BST_insert(BST_node* root, int value)
    {
        BST_node* new_node = new BST_node;
        new_node->BST_data = value;
        if (root == NULL)
        {
            root = new_node;
            return root;
        }

        if (new_node->BST_data < root->BST_data)
        {
            root->BST_left = BST_insert(root->BST_left, value);
        }
        else if (new_node->BST_data > root->BST_data)
        {
            root->BST_right = BST_insert(root->BST_right, value);
        }

        return root;
    }

    //BST Recursive search
    BST_node* recursiveSearch(BST_node* root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->BST_data == val)
        {
            return root;
        }
        else if (val < root->BST_data)
        {
            return recursiveSearch(root->BST_left, val);
        }
        else
        {
            return recursiveSearch(root->BST_right, val);
        }

        return NULL;
    }


    //Check Height of BST
    int height_BST(BST_node* rot)
    {
        if (rot == NULL)
            return -1;
        else
        {

            int lheight = height_BST(rot->BST_left);
            int rheight = height_BST(rot->BST_right);

            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    //Chek Balncing Factor BST
    int BalanceF_BST(BST_node* temp)
    {
        int l_height = height_BST(temp->BST_left);
        int r_height = height_BST(temp->BST_right);
        int b_factor = l_height - r_height;

        return b_factor;
    }


    //BGI Functions For BST
    void BST_Node_D(BST_node* root, int x, int y, int noderatio)
    {
        int bf = BalanceF_BST(root);
        if (bf > 1 || bf < -1)
        {
            setcolor(15);
            circle(x, y, 35);
            setfillstyle(SOLID_FILL, 11);
            floodfill(x, y, WHITE);
        }
        else if (bf == 1 || bf == -1)
        {
            setcolor(9);
            circle(x, y, 25);
            setfillstyle(SOLID_FILL, 10);
            floodfill(x, y,LIGHTBLUE);
        }
        else
        {
            setcolor(15);
            circle(x, y, 25);
            setfillstyle(SOLID_FILL, 11);
            floodfill(x, y, WHITE);
        }

        char arr[5];
        itoa(root->BST_data, arr, 10);
        outtextxy(x, y, arr);

        if (root->BST_left != NULL)
        {
            line(x, y, x - 20 * noderatio, y + 70);
            BST_Node_D(root->BST_left, x - 20 * noderatio, y + 70, noderatio - 2);
        }
        if (root->BST_right != NULL)
        {
            line(x, y, x + 20 * noderatio, y + 70);
            BST_Node_D(root->BST_right, x + 20 * noderatio, y + 70,
                noderatio - 2);
        }
    }


     void BST_Tree_D(BST_node* root, int x, int y)
     {

         setcolor(11);
         settextstyle(10, HORIZ_DIR, 3);
         outtextxy(520, 20, "BST TREE KEYS ");
         line(0, 50, 1500, 50);
         BST_Node_D(root, x, y, 8);
     }

    void Search_Node_D(BST_node* root, int x, int y)
    {
        setcolor(15);
        circle(x, y, 25);
        setfillstyle(SOLID_FILL, 1);
        floodfill(x, y,WHITE);

        char arr[5];
        itoa(root->BST_data, arr, 10);
        outtextxy(x, y, arr);
    }

    void Search_D(BST_node* root, int x, int y)
    {
        setcolor(11);
        settextstyle(10, HORIZ_DIR, 3);

        outtextxy(450, 20, " Search Keys in BST ");
        line(0, 50, 1500, 50);

        settextstyle(10, HORIZ_DIR, 2);
        Search_Node_D(root, x, y);
    }

    //Display Node Function
    void printPreorder(BST_node* r)
    {
        if (r == NULL)
        {
            return;
        }

        cout << r->BST_data << " ";
        printPreorder(r->BST_left);
        printPreorder(r->BST_right);
    }

};

class AVL_node {
public:
    int AVL_data;
    AVL_node* AVL_right;
    AVL_node* AVL_left;
    BST BST_obj;

    AVL_node()
    {
        AVL_data = 0;
        AVL_left = AVL_right = NULL;
    }
};

class AVL {

public:

    //AVL Node Root 
    AVL_node* root;

    AVL()
    {
        root = NULL;
    }

    //check Empty Function
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Access Rooot Function
    AVL_node* getroot()
    {
        return root;
    }

    //Check Height of AVL
    int height_AVL(AVL_node* rot)
    {
        if (rot == NULL)
            return -1;
        else
        {

            int lheight = height_AVL(rot->AVL_left);
            int rheight = height_AVL(rot->AVL_right);

            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    //ROTATIONS
    AVL_node* rr_rotation(AVL_node* parent)
    {
        AVL_node* temp;
        temp = parent->AVL_right;
        parent->AVL_right = temp->AVL_left;

        temp->AVL_left = parent;

        return temp;
    }

    AVL_node* ll_rotation(AVL_node* parent)
    {

        AVL_node* temp;
        temp = parent->AVL_left;
        parent->AVL_left = temp->AVL_right;
        temp->AVL_right = parent;

        return temp;
    }

    AVL_node* lr_rotation(AVL_node* parent)
    {
        AVL_node* temp;
        temp = parent->AVL_left;
        parent->AVL_left = rr_rotation(temp);
        return ll_rotation(parent);
    }

    AVL_node* rl_rotation(AVL_node* parent)
    {
        AVL_node* temp;
        temp = parent->AVL_right;
        parent->AVL_right = ll_rotation(temp);
        return rr_rotation(parent);
    }

    //FOR Balancing AVL Tree Functions
    AVL_node* balanceTree(AVL_node* root)
    {
        int choice;
        if (root == NULL) {
            return NULL;
        }

        root->AVL_left = balanceTree(root->AVL_left);

        root->AVL_right = balanceTree(root->AVL_right);

        root = balance(root);
        return root;
    }

    AVL_node* balance(AVL_node* temp)
    {
        int bal_factor = BalanceF_AVL(temp);

        if (bal_factor > 1)
        {
            if (BalanceF_AVL(temp->AVL_left) > 0)
            {

                temp = ll_rotation(temp);
            }

            else
            {
                temp = lr_rotation(temp);
            }
        }
        else if (bal_factor < -1)
        {
            if (BalanceF_AVL(temp->AVL_right) > 0)
            {
                temp = rl_rotation(temp);
            }

            else
            {
                temp = rr_rotation(temp);
            }
        }

        return temp;
    }

    //AVL Insertion
    AVL_node* AVL_insert(AVL_node* root, int data)
    {
        AVL_node* new_node = new AVL_node;
        new_node->AVL_data = data;
        if (root == NULL)
        {
            root = new_node;
            return root;
        }

        if (new_node->AVL_data < root->AVL_data)
        {
            root->AVL_left = AVL_insert(root->AVL_left, data);
        }
        else if (new_node->AVL_data > root->AVL_data)
        {
            root->AVL_right = AVL_insert(root->AVL_right, data);
        }

        return root;
    }

    //AVL Recursive search
    AVL_node* recursiveSearch(AVL_node* root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->AVL_data == val)
        {
            return root;
        }
        else if (val < root->AVL_data)
        {
            return recursiveSearch(root->AVL_left, val);
        }
        else
        {
            return recursiveSearch(root->AVL_right, val);
        }

        return NULL;
    }

    //Display AVL Functions
    void printPreorder(AVL_node* r) //(current node, Left, Right) 
    {
        if (r == NULL)
        {
            return;
        }

        cout << r->AVL_data << " ";
        printPreorder(r->AVL_left);
        printPreorder(r->AVL_right);
    }

    //Chek Balncing Factor AVL
    int BalanceF_AVL(AVL_node* temp)
    {
        int l_height = height_AVL(temp->AVL_left);
        int r_height = height_AVL(temp->AVL_right);
        int b_factor = l_height - r_height;

        return b_factor;
    }

    //BGI Functions For AVL
    void AVL_Node_D(AVL_node* root, int x, int y, int noderatio)
    {
        int bf = BalanceF_AVL(root);

        if (bf == 1 || bf == -1)
        {
            setcolor(9);
            circle(x, y, 25);
            setfillstyle(SOLID_FILL, 11);
            floodfill(x, y, LIGHTBLUE);
        }
        else
        {
            setcolor(15);
            circle(x, y, 25);
            setfillstyle(SOLID_FILL, 10);
            floodfill(x, y, WHITE);
        }

        char arr[5];
        itoa(root->AVL_data, arr, 10);

        outtextxy(x, y, arr);

        if (root->AVL_left != NULL)
        {
            line(x, y, x - 20 * noderatio, y + 70);
            AVL_Node_D(root->AVL_left, x - 20 * noderatio, y + 70, noderatio - 2);
        }
        if (root->AVL_right != NULL)
        {
            line(x, y, x + 20 * noderatio, y + 70);
            AVL_Node_D(root->AVL_right, x + 20 * noderatio, y + 70, noderatio - 2);
        }
    }

};

//Main Implementation Class
class Implementation {

public:
    AVL avl_obj;
    BST bst_obj;
    int item = 0;

    //Insertion
    void insert(int x_cord, int y_cord)
    {
        string str = "";
        char chr;
        int a = 0;
        int b = 76;

        while (1)
        {

            chr = getch();

            if (chr >= '0' && chr <= '9')    //Numbers
            {

                str = str + chr;
                char ch[5];

                ch[0] = chr;
                ch[1] = NULL;
                ch[2] = NULL;
                ch[3] = NULL;
                ch[4] = NULL;

                outtextxy(x_cord + a, y_cord, ch);
                a = a + 12;
            }

            else if (chr == 8)  //Backspace 
            {
                a = a - 12;
                outtextxy(x_cord + a, b, "  ");
            }

            else if (chr == 13)  //Enter
            {
                outtextxy(x_cord, 76, "        ");

                item = std::stoi(str);   //string to integer
                int    data = item % 10;

                AVL_node* temp_rot = avl_obj.getroot();
                AVL_node* temp_search = avl_obj.recursiveSearch(avl_obj.root, data);


                //IF NULL theN AVL insert
                if (temp_search == NULL)
                {
                    avl_obj.root = avl_obj.AVL_insert(avl_obj.root, data);
                    avl_obj.root = avl_obj.balanceTree(avl_obj.root);
                    avl_obj.AVL_Node_D(avl_obj.root, x, y, 8);
                    break;
                }
                //BST Inserrt
                temp_search = avl_obj.recursiveSearch(avl_obj.root, data);
                temp_search->BST_obj.BST_root = temp_search->BST_obj.BST_insert(temp_search->BST_obj.BST_root, item);
                return;

            }

        }

    }


    //search function
    void search(int x_cord, int y_cord)
    {

        string str;
        char chr;
        int a = 0;
        int b = 76;

        while (1)
        {
            chr = getch();

            if (chr >= '0' && chr <= '9')   //Number
            {

                str = str + chr;
                char ch[5];

                ch[0] = chr;
                ch[1] = NULL;
                ch[2] = NULL;
                ch[3] = NULL;
                ch[4] = NULL;

                outtextxy(x_cord + a, y_cord, ch);
                a = a + 13;

            }

            else if (chr == 8)   //Backspace
            {
                a = a - 13;

                outtextxy(x_cord + a, b, "  ");
            }
            else if (chr == 13)
            {
                outtextxy(x_cord, 76, "        ");   //Enter

                item = std::stoi(str);   //string to integer

                int  data = item % 10;

                AVL_node* temp_search = avl_obj.recursiveSearch(avl_obj.root, data);

                BST_node* temp = NULL;

                if (temp_search == NULL)
                {
                    cout << "No Key found" << endl;
                    break;
                }

                else
                {
                    if (temp_search->BST_obj.recursiveSearch(temp_search->BST_obj.BST_root, item))
                    {
                        temp = temp_search->BST_obj.recursiveSearch(temp_search->BST_obj.BST_root, item);
                        cleardevice();
                        bst_obj.Search_D(temp, x, y);
                    }
                    else
                    {
                        cout << "\n\tNot Found" << endl;
                    }
                }

            }
        }
        return;
    }

    
    //Display BST Function
    void display_bst_of_key(int x_cord, int y_cord)
    {


        string str = "";
        setcolor(11);
        settextstyle(10, HORIZ_DIR, 3);
        outtextxy(520, 20, "BST TREE KEYS ");
        line(0, 50, 1500, 50);

        settextstyle(10, HORIZ_DIR, 2);

        char chr;
        int a = 0, b = 101;
        int c = 0, d = 0;
        setcolor(15);
        outtextxy(60, 70, "Enter Key");
        rectangle(180, 70, 260, 100);
        outtextxy(183, 71, "|");


        while (!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN, c, d);
   
      
        while (1)
        {
                    
            if ((c >= 181 && c <= 259) && (d >= 70 && d <= 99))
            {
                chr = getch();

                    if (chr >= '0' && chr <= '9')   //Numbers
                    {
                        str = str + chr;
                        char ch[5];

                        ch[0] = chr;
                        ch[1] = NULL;
                        ch[2] = NULL;
                        ch[3] = NULL;
                        ch[4] = NULL;
                      
                        outtextxy(x_cord + a, y_cord, ch);
                        a = a + 10;

                    }

                    else if (chr == 8)  //Backspace
                    {
                        a = a - 10;

                        outtextxy(x_cord + a, b, "  ");
                    }
                    else if (chr == 13)   //Enter
                    {
                        outtextxy(x_cord, 101, "       ");

                        item = std::stoi(str);  //String to Integer

                        int  data = item % 10;

                        AVL_node* temp_search = avl_obj.recursiveSearch(avl_obj.root, data);
                        if (temp_search == NULL)
                        {
                            cout << "\n\tNo Key found" << endl;
                        }
                        else
                        {
                            cleardevice();
                            bst_obj.BST_Tree_D(temp_search->BST_obj.BST_root, x, y);

                            temp_search->BST_obj.printPreorder(temp_search->BST_obj.BST_root);
                            return;
                        }
                    }
            }
           
        }
     
    }
};


//Main Menu
void Menu()
{
   

    initwindow(1400, 700, "BGI Window", 50, 50);
    settextstyle(1, 0, 1);

    setcolor(3);
    outtextxy(500, 10, "VISUALIZATION");
    line(0, 40, 1500, 40);


    setcolor(15);
    outtextxy(20, 80, "Insert:");
    rectangle(100, 75, 180, 105);


    outtextxy(210, 80, "Search:");
    rectangle(305, 75, 390, 105);

    outtextxy(530, 80, "Display BST");
    rectangle(525, 70, 690, 105);


    outtextxy(1200, 85, "EXIT");
    setcolor(12);
    rectangle(1180, 75, 1290, 108);
    setcolor(15);
    line(0, 120, 1500, 120);


}


int main()
{
    Implementation obj;
    AVL obj2;

    AVL_node* temp_rot = NULL;
    Menu();

    int x = 0;
    int y = 0;
    string st;

    while (1)
    {
        //Gettig Mouse Click
        while (!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if ((x >= 102 && x <= 179) && (y >= 76 && y <= 104))
        {
            outtextxy(113, 76, "|");
            obj.insert(103, 76);

        }

        if ((x >= 306 && x <= 389) && (y >= 76 && y <= 104))
        {
            outtextxy(317, 76, "|");
            obj.search(307, 76);

        }

        if ((x >= 527 && x <= 689) && (y >= 41 && y <= 109))
        {
            cleardevice();
            obj.display_bst_of_key(183, 71);

        }

        if ((x >= 1181 && x <= 1289) && (y >= 76 && y <= 109))
        {

            return 0;
        }

    }

    system("pause");
}
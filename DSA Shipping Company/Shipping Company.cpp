#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

string productCodeGenerator();

struct Dimension {
    double length;
    double width;
    double height;
};

struct Package {
    string description;
    int quantity;
    float weight;
    Dimension dimension;
    Package* next;
};
class List {
private:
    Package* head = NULL, * last = NULL;
public:
    bool IsEmpty() { return head == NULL; }
    List() :head(NULL), last(head) {}
    void addPackage();
    void deletePackage();
    void sortPackages();
    void findPackage();
    void loggedParcels();
    void displayCargo();
    
    // ~List();


};

 void List::sortPackages() {  
        //Node current will point to head  
        Package  *current = head, *index = NULL;  
        float tempWeight,tempLength,tempWidth,tempHeight;
        string tempDesc;
        
        int ascending;
        cout << "\n<<< Sort Parcels >>>\n";
        cout << "\nSort by:";
        cout << "\n[0] heavier weight";
        cout << "\n[1] lighter weight"; 
        cout << "\n\nSelection: ";
        cin >> ascending;
          
        
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
              
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(ascending)
                {
                    if(current->weight > index->weight) {  
                        tempDesc = current->description;
                        tempWeight = current->weight;  
                        tempLength = current->dimension.length;
                        tempWidth = current->dimension.width;
                        tempHeight = current->dimension.height;
                        
                        current->description = index->description;
                        current->weight = index->weight;  
                        current->dimension.length = index->dimension.length; 
                        current->dimension.width = index->dimension.width; 
                        current->dimension.height = index->dimension.height; 
                        
                        index->description = tempDesc;
                        index->weight = tempWeight;  
                        index->dimension.length = tempLength;  
                        index->dimension.width = tempWidth;
                        index->dimension.height = tempHeight;
                    }  
                    index = index->next;  
                }else
                {
                    if(current->weight < index->weight) {  
                        tempDesc = current->description;
                        tempWeight = current->weight;  
                        tempLength = current->dimension.length;
                        tempWidth = current->dimension.width;
                        tempHeight = current->dimension.height;
                        
                        current->description = index->description;
                        current->weight = index->weight;  
                        current->dimension.length = index->dimension.length; 
                        current->dimension.width = index->dimension.width; 
                        current->dimension.height = index->dimension.height; 
                        
                        index->description = tempDesc;
                        index->weight = tempWeight;  
                        index->dimension.length = tempLength;  
                        index->dimension.width = tempWidth;
                        index->dimension.height = tempHeight;
                    }  
                    index = index->next;  
                }
                    
                    
            }  
            current = current->next;  
        }    
        cout << "\n\n[+ ] Parcels Sorted Successfully..\n";
        cout << "[+ ] Print your Digital Recipet to display it =).\n\n";
         
    }  


void List::findPackage()
{
    int selection;
    cout << "\n<<< Find Parcel >>>\n\n"; 
    cout << "Find Parcel by:";
    cout << "\n[1] dimensions";
    cout << "\n[2] weight";
    cout << "\n\nSelection: ";
    cin >> selection;
    Package* currPackage = head;
    int traverser = 1;
    bool found=false;
    double dimensions=0;
    switch(selection)
    {
        case 1:
        {
            cout << "\nEnter Dimensions: ";
            cin >> selection;
            
            while (  currPackage != NULL) {
                dimensions = (currPackage->dimension.length*currPackage->dimension.width*currPackage->dimension.height);
                if (dimensions == selection)
                {
                    found = true;
                }
                currPackage = currPackage->next;
                traverser++;
                
            }
            if(found)
            {
                cout << "\n[+ ] Parcel Found :D...\n\n";
                int size = 5;
                int currPackageDimensions = (currPackage->dimension.height * currPackage->dimension.width * currPackage->dimension.length);
                string code = productCodeGenerator(), quantity = to_string(currPackage->quantity), description = currPackage->description, weight = to_string(currPackage->weight), packageDimensions = to_string(currPackageDimensions);
                string titles[size] = { "Product Code: " + code, "Quantity: " + quantity, "Description: " + description,"Weight(kg): " + weight,"Dimensions: " + packageDimensions };
                int rows = 60;
                cout << " ";
                for (int i = 0; i < rows; i++) {
                    cout << "-";
                }
                cout << endl;
                for (int i = 0; i < size; i++) {
                    cout << "|" << titles[i];
                    double length = titles[i].length();
                    for (int j = 0; j < (rows - length); j++) {
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
                cout << " ";
                for (int i = 0; i < rows; i++) {
                    cout << "-";
                }
                
            
            }
            else{
                cout << "\n[- ] Parcel Not Found :-( ...\n\n";
            }
        }
        break;
        default:
            cout << "\n BAD REQUEST XO\n\n";
    };
    
}

void List::addPackage() {

    Package* currPackage = head, * prevPackage = NULL;
    int traverser = 1, position;
    while (currPackage != NULL) {
        currPackage = currPackage->next;
        traverser++;
    }

    currPackage = head;

    cout << "\n <<< Loging Package >>\n";
    Package* newPackage = new Package;
    cout << "\nPackage description: ";
    cin >> newPackage->description;
    cout << "Package weight: ";
    cin >> newPackage->weight;
    cout << "\n\n<<<Package Dimensions >>>\n\n";
    cout << "Package Length (cm): ";
    cin >> newPackage->dimension.length;
    cout << "Package Width (cm): ";
    cin >> newPackage->dimension.width;
    cout << "Package Height (cm): ";
    cin >> newPackage->dimension.height;
    cout << "Quantity : ";
    cin >> newPackage->quantity;



    if (last != head)
    {
        cout << "\n<<< Package position >>>\n\n";
        cout << "0) beginning\n";
        cout << "1) middle\n";
        cout << "2) end\n\n";
        cout << "\n\nSelection: ";
        cin >> position;

        switch (position) {
        case 0:
        {
           
            head = newPackage;
            head->next = currPackage;
            
            cout << "\n\nParcel Loaded in the begining successfully\n\n";
        }
        break;
        case 1:
        {
            position = traverser / 2;
            traverser = 0;
            while (traverser != position) {
                prevPackage = currPackage;
                currPackage = currPackage->next;
                traverser++;
            }
            prevPackage->next = newPackage;
            newPackage->next = currPackage;
            cout << "\n\nParcel Loaded in the middle successfully\n\n";
        }
        break;
        case 2:
        {

            
            while (currPackage != NULL) {
                currPackage = currPackage->next;

            }
            currPackage->next = newPackage;
            cout << "\n\nParcel Loaded in the end successfully\n\n";

        }
        break;
        default:
            cout << "\n! WRONG INPUT . !\n";
        };
    }
    else {
        head = newPackage;
        head->next = NULL;
    }



}

void List::loggedParcels()
{
    Package* currPackage = head;
    int totquantity = 0, totweight = 0, totdimensions = 0;
    while (currPackage != NULL) {
        int size = 5;
        int currPackageDimensions = (currPackage->dimension.height * currPackage->dimension.width * currPackage->dimension.length);
        string code = productCodeGenerator(), quantity = to_string(currPackage->quantity), description = currPackage->description, weight = to_string(currPackage->weight), packageDimensions = to_string(currPackageDimensions);
        string titles[size] = { "Product Code: " + code, "Quantity: " + quantity, "Description: " + description,"Weight(kg): " + weight,"Dimensions: " + packageDimensions };
        int rows = 60;
        cout << " ";
        for (int i = 0; i < rows; i++) {
            cout << "-";
        }
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << "|" << titles[i];
            double length = titles[i].length();
            for (int j = 0; j < (rows - length); j++) {
                cout << " ";
            }
            cout << "|" << endl;
        }
        cout << " ";
        for (int i = 0; i < rows; i++) {
            cout << "-";
        }
        cout << endl;
        totquantity += currPackage->quantity;
        totweight += currPackage->weight;
        totdimensions += currPackageDimensions;
        currPackage = currPackage->next;
    }
    
    cout << endl;
    
    int size = 3;
    string TotalQuantity = to_string(totquantity), TotalWeight = to_string(totweight * 2.2), TotalDimensions = to_string(totdimensions);
    string titles[size] = { "Total Quantity: " + TotalQuantity, "Total Weight (Ibs): " + TotalWeight, "Total Dimensions: " + TotalDimensions };
    int rows = 60;
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "|" << right << setw(productCodeGenerator().length()) << titles[i];
        double length = titles[i].length();
        for (int j = 0; j < (rows - length); j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }

}

void List::displayCargo()
{
    
    cout << "\n\n<~<~<~--     ---[FEDOX DIGITAL RECIPET]---         --~>~>~>\n\n";
    
    int size = 8;
    string exporter = "Exporter", exporterComp = "\Fedox Exports", address = "4300 Longbeach Blvd,\nLongbeach, California, 90807", senderCountry = "United States", senderPhone = "+121388443311", packageSenderName = "Randy Clark", companyTaxID = "93377112", email = "info@Fedoxexports.com";
    string exportTitles[size] = { exporter,exporterComp, address,senderCountry,senderPhone, packageSenderName,companyTaxID,email };
    int rows = 60;
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "|" << exportTitles[i];
        double length = exportTitles[i].length();
        for (int j = 0; j < (rows - length); j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }

    cout << endl;
    
    size = 6;
    string consignee = "Consignee", consigneeComp = "Global imports", receiverAddress = "410 Queen Street\nBrisbane, Queensland, 4000", receiverCountry = "Australia", receiverPhone = "+61497336120", packageReceiverName = "John Smith";
    string importTitles[size] = { consignee,consigneeComp, receiverAddress,receiverCountry, receiverPhone,packageReceiverName };
    rows = 60;
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "|" << importTitles[i];
        double length = importTitles[i].length();
        for (int j = 0; j < (rows - length); j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int i = 0; i < rows; i++) {
        cout << "-";
    }

    cout << endl;
    
    loggedParcels();
    cout << "\n\n----------------------[END OF THE RECIPET]-----------------------------\n\n";
    
}


void List::deletePackage() {

    Package* currPackage = head, * prevPackage = NULL,*temp;
    int traverser = 1, position;
    while (currPackage != NULL) {
        currPackage = currPackage->next;
        traverser++;
    }

    cout << "\n<< UNLOAD PARCEL >>\n\n";
    loggedParcels();




    currPackage = head;

    cout << "Delete:\n\n";
    cout << "\n[1] First Parcel";
    cout << "\n[2] Middle Parcel";
    cout << "\n[3] Last Parcel";
    cout << "\n\nSelect Parcel to delete: ";
    cin >> position;

  
    switch (position) {
    case 1:
    {

        temp = head;
        head = head->next;
        delete temp;
        cout << '\nFirst Parcel Deleted Successfully ":P\n\n';
        // head = newPackage;
        // head->next = currPackage;
    }
    break;
    case 2:
    {
        position = traverser / 2;
        traverser = 0;
        while (traverser != position) {
            prevPackage = currPackage;
            currPackage = currPackage->next;
            traverser++;
        }
        temp = currPackage;
        currPackage = currPackage->next;
        prevPackage->next = currPackage;
        // prevPackage->next = newPackage;
        // newPackage->next = currPackage;
        delete temp;
        cout << '\nMiddle Parcel Deleted Successfully ":P\n\n';

    }
    break;
    case 3:
    {
        temp = last;
        Package *beforeLast = head;
        while (beforeLast != last)
            beforeLast = beforeLast->next;
            last = beforeLast;
        delete temp;
        cout << '\nLast Parcel Deleted Successfully ":P\n\n';

        // last->next = newPackage;
        // last = last->next;
        // last->next = NULL;
    }
    break;
    default:
        cout << "\n! WRONG INPUT . !\n\n";
    };




}

int GUI()
{
    int o;
    cout << "\n\n" << right << setw(20) << "<< [WELCOME TO FedoX] >>\n";
    cout << "[+] your risk of shapping with us less than 1% ;)\n\n";
    cout << "<<< user interface >>>";
    cout << "\n[1] Load parcel/s";
    cout << "\n[2] unload parcel/s";
    cout << "\n[3] find parcels";
    cout << "\n[4] sort parcels [Not Available]";
    cout << "\n[5] digital recipet";
    cout << endl;
    cout << "Selection: ";
    cin >> o;
    return o;

}

int main()
{
    int selection;
    int size;
    List cargo;




    while (1)
    {
        selection = GUI();
        switch (selection)
        {
        case 1:
        {
            cout << "\nHow many packages you want to ship ? ";
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cargo.addPackage();
            }
        }
        break;
        case 2:
        {
            if (cargo.IsEmpty())
                cout << "\nNo Parcels are being loaded yet :O) !\n\n";
            else
            {
                cargo.deletePackage();
            }
        }
        break;
        case 3:
        {
            if (cargo.IsEmpty())
                cout << "\nNo Parcels are being loaded yet :O) !\n\n";
            else
            {
                cargo.findPackage();
            }
        }
        break;
        case 4:
        {
            if (cargo.IsEmpty())
                cout << "\nNo Parcels are being loaded yet :O) !\n\n";
            else
            {
                cargo.sortPackages();
            }
        }
        break;
        case 5:
        {
            if (cargo.IsEmpty())
                cout << "\nNo Parcels are being loaded yet :O) !\n\n";
            else
            {
                cargo.displayCargo();
            }
            
        }
        break;
        default:
            cout << "\n\n[!! ] BAD REQUEST XO\n\n";


        }
    }

}

string productCodeGenerator() {



    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    string productId;
    char c;
    int r;
    int num = 2;
    srand(time(NULL));    // initialize the random number generator
    for (int i = 0; i < num; i++)
    {
        r = rand() % 26;   // generate a random number
        c = 'A' + r;            // Convert to a character from a-z
        productId += c;
    }
    productId += to_string(rand());

    // display 5 random numbers per row
    // if (count % 5 == 0)
    //     std::cout << "\n";
    return productId;

}

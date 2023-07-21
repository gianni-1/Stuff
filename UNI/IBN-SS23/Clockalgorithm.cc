#include <vector>
#include <iostream>

class ClockAlgorithm
{
private: 
    int num_frames;                  //Anzahl frames
    std::vector<int> frames;         //Die "tatsächlichen frames"
    std::vector<bool> ref_bits;      //R -bits
    int lbeginning;                  //index des Listenanfangs

public:
    ClockAlgorithm(int num_frames) : num_frames(num_frames), lbeginning(0)
    {
        //framesanzahl wird mit num_frames initialisiert und alle frames die nicht besetzt sind Wert -1
        frames = std::vector<int>(num_frames, -1);            
        ref_bits = std::vector<bool>(num_frames, false);      // alles R-bits anfänglich  0 bzw. false
    }

    void access_page(int page_num)
    {
        for (int i = 0; i < num_frames; i++)
        {
            if (frames[i] == page_num)        //wenn pagenumber bereits geladen ist wird r-bit auf 1 bzw. true
            {
                ref_bits[i] = true;
                return;                       
            }
        }

        while (true)
        {
            /*  der anfang wird so lange nach rechts verschoben,bis anfang der Liste das r-bit nicht gesetzt ist, dann wird die neue page 
                zunächst am anfang eingefügt und dann der Anfang um eins nach rechts verschoben
            */
            if (ref_bits[lbeginning] == false)        
            {
                frames[lbeginning] = page_num;
                lbeginning = (lbeginning + 1) % num_frames;
                return;
            }
            ref_bits[lbeginning] = false;
            lbeginning = (lbeginning + 1) % num_frames;
        }
    }

    void print_frames()
    {
        for (int i = 0; i < num_frames; i++)
        {
            if (frames[i] != -1)
            {
                std::cout << frames[i] << " ";
            }
            else
            {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
    ClockAlgorithm clockA(3);
    ClockAlgorithm clockB(3);
    std::vector<int> accessesA = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    std::vector<int> accessesB = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};

    std::cout << "Referenzfolge A: " << std::endl;
    for (int access : accessesA)
    {
        clockA.access_page(access);
        std::cout << access << ": " <<std::flush;
        clockA.print_frames();
    }

    std::cout << std::endl;

    std::cout << "Referenzfolge B: " << std::endl;
    for(int access : accessesB)
    {
        clockB.access_page(access);
        std::cout << access << ": " << std::flush;
        clockB.print_frames();
    }





    return 0;
}

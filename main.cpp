#include <iostream>
using namespace std;

char * names[] = {"Massless void","Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon","Sodium","Magnesium","aluminium","Silicon","Phosphorus","Sulphur","Chlorine","Argon","Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirkonium","Niobium","Molybdaenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon","Cesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Hydrargyrum","Thallium","Lead","Bismuth","Polonium","Astatine","Radon","Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Ununnilium","Unununium"};
/*
 
 1s2
 2s2	2p6
 3s2	3p6	3d10
 4s2 4p6	4d10 4f14
 5s2 5p6 5d10 5f14 5g18
 6s2 6p6 6d10 6f14
 7s2 7p6 7d10
 8s2 8p6
 9s2
 */
double A [] = {0.0f,1.00794,4.002602,6.941,9.012182,10.811,12.0107,14.0067,15.9994,18.9994,20.1797,22.98976928,24.305,26.9815386,28.0855,30.973762,32.065,35.453,39.948,39.0983,40.078,44.955912,47.867,50.9415,51.9961,54.938045,55.845,58.933195,58.6934,63.546,65.38,69.723,72.64,74.9216,78.96,79.904,83.798,85.4678,87.62,88.90585,91.224,92.90638,95.96,98,101.07,102.9055,106.42,107.8682,112.411,114.818,118.71,121.76,127.6,126.90447,131.293,132.9054519,137.327,138.90547,140.116,140.90765,144.242,145,150.36,151.964,157.25,158.92535,162.5001,164.93032,167.259,168.93421,173.054,174.9668,178.49,180.94788,183.84,186.207,190.23,192.217,192.084,196.966569,200.59,204.3833,207.2,208.980401,210,210,220,223,226,227,232.03806,231.03588,238.02891,237,244,243,247,247,251,252,257,258,259,262,261,262,266,264,277,268,271,272};


char ptable[][3]={
	"",
	"H" ,"He",
	"Li","Be","B" ,"C" ,"N" ,"O" ,"F" ,"Ne",
	"Na","Mg","Al","Si","P" ,"S" ,"Cl","Ar",
	"K" ,"Ca","Sc","Ti","V" ,"Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
	"Rb","Sr","Y" ,"Zr","Nb","Mo","Te","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I" ,"Xe",
	"Cs","Ba","La",
	//Lanthanides
	"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
	"Hf","Ta","W" ,"Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
	"Fr","Ra","Ac",
	//Actinides
	"Th","Pa","U" ,"Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr",
	"Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg"
	
	
	
	
	
};
char sst[]= {	//energy level
	's',
	's',
	'p','s',
	'p','s',
	'd','p','s',
	'd','p','s',
	'f','d','p','s',
	'f','d','p','s',
	'g','f','d','p','s'
	
	
};



unsigned long hold[]={//subshell can hold
	2,
	2,
	6,2,
	6,2,
	10,6,2,
	10,6,2,
	14,10,6,2,
	14,10,6,2,
	18,14,10,6,2
	
	
};
unsigned long belong[]={//shell
	
	1,
	2,
	2,3,
	3,4,
	3,4,5,
	4,5,6,
	4,5,6,7,
	5,6,7,8,
	5,6,7,8,9
};
void showcharge(unsigned long ss,unsigned long e)
{
	unsigned long max = hold[ss];
	if(e>(max>>1))
	{
		cout<<"-"<<(max-e);
		
	}
	else
	{
		cout<<"+"<<e;
	}
	
}		

int main (int argc, char * const argv[]) {
	if(argc<2){cout<<"\nUsage : "<<argv[0]<<"[-n Fe]/[26]"<<endl;return 1;}
	unsigned long n,c,s,l;
	unsigned long wholeshell[12];
	for(n=0;n<12;++n){
		wholeshell[n]=0;
	}	
	bool found=false;
	if(argc>=3)
	{
		
		if(argv[1][0]=='-')
		{	
			if(argv[1][1]=='c'||argv[1][1]=='n')
			{
				l=strlen(argv[2]);
				for(n=0;n<=111;++n)
				{
					if(strlen(ptable[n])==l)
					{
						if(ptable[n][0]==argv[2][0])
						{
							
							if(l>1)
							{
								if(ptable[n][1]==argv[2][1]){found=true;break;}
							}
							else{found=true;break;}
						}
					}
				}
				if(!found){cout<<"Could not find element: "<<argv[2]<<endl;return 5;}
			}
		}
	}
	if(!found){n=atoi(argv[1]);}
	if(n>111){cout<<"Too high. Maximum is 111, "<<names[111]<<endl;return 2;}
	cout<<"Periodic Table: "<<names[n]<<" ("<<ptable[n]<<") Z="<<n<<", A="<<A[n]<<endl;
	cout<<"Electron configuration\n";
	//s=subshell id
	for(c=n,s=0;;++s)
	{
		if(c<=hold[s]){wholeshell[belong[s]]+=c;cout<<" "<<belong[s]<<sst[s]<<c;cout<<endl;cout<<"Valence electrons: ";showcharge(s,c);cout<<endl;c=0; break;}
		else
		{
			wholeshell[belong[s]]+=hold[s];
			cout<<" "<<belong[s]<<sst[s]<<hold[s];c-=hold[s];
			
		}
	}
	cout<<"Whole Shell: "<<wholeshell[1];
	for(n=2;n<12;++n){
		if(wholeshell[n]!=0)
		{
			cout<<","<<wholeshell[n];
		}
	}	
	cout<<endl;
    return 0;
}

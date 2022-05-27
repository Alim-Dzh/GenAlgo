#include <iostream>
#include <random>
#include <math.h>
#include <stdlib.h> // ����� ��� ������ ������� rand(), srand()
#include <time.h> // ����� ��� ������ ������� time()

using namespace std;


string binary(int n, int B)
{
	int logi = (int) ceil((log(B)) / (log(2)));
	string bitX;
	//bitX += n < 0 ? "0" : "1";
	do
	{
		bitX += char('0' + n % 2); // ��������� � �����

		n = n / 2;

	} while (n > 0);

	while (bitX.length() < logi) {

		bitX.append("0");

	}

	return string(bitX.crbegin(), bitX.crend()); // ������������� ���������
}


//��������� ����� �� min �� max
int randInt(int min, int max) {
	random_device random_device;
	mt19937 generator(random_device());

	uniform_int_distribution<> distribution(min, max);

	int x = distribution(generator);
	if (x < max) {
		return x + 1;
	}
	else if (min == 0) {
		int sec = time(NULL);
		if (sec % 2 == 0) {
			return 0;
		}
		else if (sec % 3 == 0) {
			return 1;
		}
	}
	return x;
}


//������� ���������� ���� ������� �������
int findMinRec(int* fY, int n)
{
	if (n == 1) {
		return fY[0];
	}
	return min(fY[n - 1], findMinRec(fY, n - 1));

}

int findMinRec2(int* fY, int n)
{
	if (n == 1) {
		return fY[0];
	}
	return max(fY[n - 1], findMinRec(fY, n - 1));


}

double function(int x) {
	double num = pow(x, 2) - 2* pow(x, 1) + 4;
	return num;
}

// A -> 2 
// x1 -> 3



//�����������
string* Crossover(string* fBit, int indexMin, int B,int sizePopulation)
{
	int logi = ceil((std::log(B)) / (std::log(2)));

	int flag = 1, n = sizePopulation, newFlag = 0;

	int iParrFirst , iParrSecond;

	string strOne, strTwo, strOneCopy, strTwoCopy;

	string* NewFuncBit = new string[n + 1];



	for (int j = 0; j < n + 1; j++) {

		//cout << "j " << j << endl;

		//for (int k = 0; k < n; k++) {
		//	//cout << "fBit" << k << " " << fBit[k] << endl;
		//}

		//cout << "flag " << flag << endl;
		//cout << "else" << endl;
		//cout << "j " << j << endl;
		//cout << "random" << newFlag << endl;

		newFlag = randInt(0, logi);

		if (newFlag == logi) {
			newFlag -= 1;
		}
		
		iParrFirst = j; //j ������

		if (j == n) {
			//cout << "IndexMin" << endl;
			iParrFirst = indexMin; // indexMin �������� ������ ���!
			//cout << "minParrFirst" << iParrFirst << endl;
		}
		
		int iParrSecond = newFlag; //�������� ��������� ������

		if (iParrFirst == iParrSecond) {
			//cout << "copy to copy!!!" << endl;
			if (iParrFirst != 0) {
				iParrSecond -= 1;
			}
			else {
				iParrSecond += 1;
			}
		}
		
		strOne = fBit[iParrFirst];
		strTwo = fBit[iParrSecond];

		strOneCopy = fBit[iParrFirst];
		 strTwoCopy = fBit[iParrSecond];

		strOneCopy.assign(strOne, newFlag + 1, size(strOne)); //cout << "StrOneCopy2 " << strOneCopy << endl;

		strTwoCopy.assign(strTwo, newFlag + 1, size(strTwo)); //cout << "StrTwoCopy2 " << strTwoCopy << endl;

		strOne.erase(newFlag + 1); //cout << "StrOne ����� �������� " << strOne << endl;

		strTwo.erase(newFlag + 1); //cout << "StrTwo ����� �������� " << strTwo << endl;

		strOne.append(strTwoCopy); //cout << "StrOne ���� " << strOne << endl;

		strTwo.append(strOneCopy);// cout << "StrTwo ���� " << strTwo << endl;

		NewFuncBit[j] = strOne;

		//NewFuncBit[j + 1] = strTwo;

		cout << "---------------------------------------" << endl;

		cout << "������ �������� - " << fBit[iParrFirst] << " | ������ �������� - " << fBit[iParrSecond] << " | ������� 1 - " << strOne << " | ������� 2 - " << strTwo << " ���� " << newFlag << endl;

		cout << "---------------------------------------" << endl;

	}
	return NewFuncBit;
	cout << "��� �����!";
	delete[]NewFuncBit;
}




void Mutation(string* funcX, int B) {

	int logi = ceil((std::log(B)) / (std::log(2)));

	for (int i = 0; i < 6; i++) {

		//�����!
		int newRandInt = randInt(0, 100);
		int randGen = randInt(0, logi);

		if (randGen == logi) {
			randGen -= 1;
		}
		//�����!

		if (newRandInt < 50) {

			if (funcX[i][randGen] == '0') {
				//cout << "Before = " << funcX[i] << " -- " << funcX[i][randGen] << "randGen" << randGen << endl;
				funcX[i][randGen] = '1';
				//cout << "After = " << funcX[i] << " -- " << funcX[i][randGen] << endl;
			}
			else {
				//cout << "Before = " << funcX[i] << " -- " << funcX[i][randGen] << "randGen" << randGen << endl;
				funcX[i][randGen] = '0';
				//cout << "After = " << funcX[i] << " -- " << funcX[i][randGen] << endl;
			}

		}

	}
	
}


// ������� �� 10 -> 2 ��
void reBinary(int* A, int newB, int newA, string* S, int n) {
	int log = ceil((std::log(newB)) / (std::log(2)));
	int rez = 0;
	int x = 0, k = 0;

	for (int i = 0; i < n + 1; i++) {
		k = 0;
		rez = 0;
		//cout << "-------------------" << "My Test" << "---------------------------" << endl;

		//cout << "log " << log << endl;

		//cout << "S[i] " << S[i];
		
		for (int j = log - 1; j >= 0; j--) {

			int x = S[i][j] - '0';

			rez += x * pow(2, k);

			k += 1;

			//cout << "X -- " << x;
		}
		if (rez <= newB && rez >= newA) {
			A[i] = rez;
		}
		else if (rez <= newA) {
			rez += newA - rez ;
			A[i] = rez;
		}
		else if (rez >= newB) {
			rez -=  rez - newB ;
			A[i] = rez;
		}
		

		//cout << "A[i] = " << A[i] << endl;

	}
}


int comp(const void* a, const void* b) {
	
	return (*((int*)(a))-*(int*)b);
	
}

int comp2(const void* a, const void* b) {

	return (*(int*)b - *(int*)(a));

}

//"������������ �����"
void Selection(int* funcX, int* Child, int* Rez, int*YRez, int n, int f ,int *Y, int* X) {
	int timeY, timeX;
	int len = 2 * n + 1;

	for (int i = 0; i < len/2 ; i++) {
		Rez[i] = funcX[i];
	}

	for (int j = len/2 ; j < len; j++) {
		Rez[j] = Child[j - (len/2)];
	}

	for (int k = 0; k < len; k++) {
		YRez[k] = function(Rez[k]);
	}

	if (f == 1) {
		//qsort(YRez, len, sizeof(int), comp);

		while (len--)
		{
			bool swapped = false;

			for (int i = 0; i < len; i++)
			{
				if (YRez[i] > YRez[i + 1])
				{
					//swap(list[i], list[i + 1]);
					timeY = YRez[i];
					YRez[i] = YRez[i + 1];
					YRez[i + 1] = timeY;

					timeX = Rez[i];
					Rez[i] = Rez[i + 1];
					Rez[i + 1] = timeX;
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}
	}
	else {
		//qsort(YRez, len, sizeof(int), comp2);
		while (len--)
		{
			bool swapped = false;

			for (int i = 0; i < len; i++)
			{
				if (YRez[i] < YRez[i + 1])
				{
					//swap(list[i], list[i + 1]);
					timeY = YRez[i];
					YRez[i] = YRez[i + 1];
					YRez[i + 1] = timeY;

					timeX = Rez[i];
					Rez[i] = Rez[i + 1];
					Rez[i + 1] = timeX;
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}
	}

	if (f == 1) {
		if (YRez[0] < *Y) {
			*Y = YRez[0];
			*X = Rez[0];
		}

	}
	else {
		if (Rez[0] > *Y) {
			*Y = YRez[0];
			*X = Rez[0];
		}
	}

	cout << "------------ StopPoint -----------------" << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Rez" << i << " = " << Rez[i] << endl;
		cout << "YRez" << i << " = " << YRez[i] << endl;

	}
	cout << "------------ StopPoint -----------------" << endl;
}



int* GenMin(int A, int B, int** nextArr,int flag) {
	int minFunc,xMinFunc; // ������� �������

	
	int sizeStartPopulation; //����� ��������� ���������,������ �� ���������
	int lenInterval = B - A;

	if (lenInterval <= 10) {
		sizeStartPopulation = 6;
	}
	else if (lenInterval <= 50 && lenInterval > 10) {
		sizeStartPopulation = 10;
	}
	else if (lenInterval <= 100  && lenInterval > 50) {
		sizeStartPopulation = 20;
	}
	else if (lenInterval <= 1000 && lenInterval > 100) {
		sizeStartPopulation = 50;
	}
	else {
		sizeStartPopulation = 100;
	}

	// "��������" ������,������ ����� �������� ��������� ���������
	int* rezArr = new int[(2 * sizeStartPopulation) + 1];

	// �������� ������ �������
	int* YRez = new int[(2 * sizeStartPopulation) + 1];

	// �������� ��������� �
	int* funcX = new int[sizeStartPopulation];

	// �������� Y ��� ��������� X
	int* funcY = new int[sizeStartPopulation];

	// ������������ ����
	int* Child = new int[sizeStartPopulation];

	// ������� �-��������
	string* funcBit = new string[sizeStartPopulation];

	// ������� ����
	string* childBit = new string[sizeStartPopulation + 1];

	//--------------------------------------------------------------------------------------------------
	// ���������� ��������� ���������
	
	if (flag == 1) {
		for (int i = 0; i < sizeStartPopulation; i++) {
			if (i == 0) {
				funcX[i] = A;
				funcY[i] = function(A);
				funcBit[i] = binary(A, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";
			}
			else if (i == 1) {
				funcX[i] = B;
				funcY[i] = function(B);
				funcBit[i] = binary(B, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";
			}
			else {
				int random = randInt(A, B);
				funcX[i] = random;
				funcY[i] = function(random);
				funcBit[i] = binary(random, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";

			}
		}
	}
	else {
		funcX = *nextArr;

		for (int i = 0; i < sizeStartPopulation; i++) {

			//funcX[i] = A;
			funcY[i] = function(funcX[i]);
			funcBit[i] = binary(funcX[i], B);
			cout << "---------------------------------------" << endl;
			cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
			cout << " Y" << i + 1 << " = " << funcY[i] << endl;
			cout << "---------------------------------------";

		}
	}
	
	//--------------------------------------------------------------------------------------------------
	// ����� ������� ������ � ��� ������ � ������� "�������",��� �� ���� �������� ������� ������ ����� �����
	cout << "StopPoint2";
	int IndexMin = 0;
	int Min = findMinRec(funcY, sizeStartPopulation);
	
	for (int i = 0; i < sizeStartPopulation; i++) {
		cout << "FuncY" << i << " " << funcY[i] << endl;
		if (funcY[i] == Min) {
			IndexMin = i;
			xMinFunc = i;
			break;
		}
	}
	
	minFunc = Min;

	//cout << "MIN = " << Min << endl;
	//cout << "IndexMin " << IndexMin << endl;


	//--------------------------------------------------------------------------------------------------
	
	// ���������� "������� ���������" ���������
	childBit = Crossover(funcBit, IndexMin, B, sizeStartPopulation);
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		//cout << "ChildBit : " << i  << " " << childBit[i] << endl;
	}
	cout << "StopPoint3";
	//--------------------------------------------------------------------------------------------------
	// �������� ��������� 
	Mutation(childBit, B);

	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//cout << "������������ ����! " << childBit[i] << endl;
	}
	
	//--------------------------------------------------------------------------------------------------
	// ��������� �� 2 -> 10 
	reBinary(Child, B, A,childBit, sizeStartPopulation); // �� ChildBit (�����) ������������ � Child(�����),��� �� �������������!
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		//cout << "Child" << i << " " << Child[i] << endl;
	}
	
	//--------------------------------------------------------------------------------------------------
	// �� ��������� �������� ���,��� ������ ������!
	Selection(funcX, Child, rezArr, YRez, sizeStartPopulation,1, &minFunc ,& xMinFunc);
	//int minFunc, xMinFunc; // ������� �������
	cout << "minFunc " << minFunc << endl;
	cout << "xMinFunc " << xMinFunc << endl;
	if (flag == 1) {
		return rezArr;
	}
	else {
		*nextArr = rezArr;
	}
	
}

//-----------------------------COPY---------------------------------------------------------------------

/*void GenMin2(int A, int B, int** newPopulation) {
	int minFunc, xMinFunc; // ������� �������


	int sizeStartPopulation; //����� ��������� ���������,������� �� ���������
	int lenInterval = B - A;

	if (lenInterval <= 10) {
		sizeStartPopulation = 6;
	}
	else if (lenInterval <= 50 && lenInterval > 10) {
		sizeStartPopulation = 10;
	}
	else if (lenInterval <= 100 && lenInterval > 50) {
		sizeStartPopulation = 20;
	}
	else if (lenInterval <= 1000 && lenInterval > 100) {
		sizeStartPopulation = 50;
	}
	else {
		sizeStartPopulation = 100;
	}

	// "��������" ������,������ ����� �������� ��������� ���������
	int* rezArr = new int[(2 * sizeStartPopulation) + 1];
	//rezArr = newPopulation;
	// �������� ������ �������
	int* YRez = new int[(2 * sizeStartPopulation) + 1];

	// �������� ��������� �
	int* funcX = new int[sizeStartPopulation];

	funcX = *newPopulation;
	
	// �������� Y ��� ��������� X
	int* funcY = new int[sizeStartPopulation];

	// ������������ ����
	int* Child = new int[sizeStartPopulation];

	// ������� �-��������
	string* funcBit = new string[sizeStartPopulation];

	// ������� ����
	string* childBit = new string[sizeStartPopulation + 1];

	//--------------------------------------------------------------------------------------------------
	// ���������� ��������� ���������

	
	for (int i = 0; i < sizeStartPopulation; i++) {

		//funcX[i] = A;
		funcY[i] = function(funcX[i]);
		funcBit[i] = binary(funcX[i], B);
		cout << "---------------------------------------" << endl;
		cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
		cout << " Y" << i + 1 << " = " << funcY[i] << endl;
		cout << "---------------------------------------";

	}
	
	

	//--------------------------------------------------------------------------------------------------
	// ����� ������� ������ � ��� ������ � ������� "�������",��� �� ���� �������� ������� ������ ����� �����
	int IndexMin = 0;
	int Min = findMinRec(funcY, sizeStartPopulation);

	for (int i = 0; i < sizeStartPopulation; i++) {
		//cout << "FuncY" << i << " " << funcY[i] << endl;
		if (funcY[i] == Min) {
			IndexMin = i;
			xMinFunc = i;
			break;
		}
	}
	minFunc = Min;
	//cout << "MIN = " << Min << endl;
	//cout << "IndexMin " << IndexMin << endl;


	//--------------------------------------------------------------------------------------------------
	// ���������� "������� ���������" ���������
	childBit = Crossover(funcBit, IndexMin, B, sizeStartPopulation);
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		//cout << "ChildBit : " << i << " " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �������� ��������� 
	Mutation(childBit, B);

	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//cout << "������������ ����! " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// ��������� �� 2 -> 10 
	reBinary(Child, B, A, childBit, sizeStartPopulation); // �� ChildBit (�����) ������������ � Child(�����),��� �� �������������!
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		//cout << "Child" << i << " " << Child[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �� ��������� �������� ���,��� ������ ������!
	Selection(funcX, Child, rezArr, YRez, sizeStartPopulation, 1, &minFunc, &xMinFunc);
	//int minFunc, xMinFunc; // ������� �������
	cout << "minFunc " << minFunc << endl;
	cout << "xMinFunc " << xMinFunc << endl;
	*newPopulation = rezArr;
}
*/
int* GenMax(int A, int B,int** nextArr,int flag) {
	int maxFunc,xMaxFunc; // ������� �������
	int sizeStartPopulation; //����� ��������� ���������,������ �� ���������
	int lenInterval = B - A;

	if (lenInterval <= 10) {
		sizeStartPopulation = 6;
	}
	else if (lenInterval <= 50 && lenInterval > 10) {
		sizeStartPopulation = 10;
	}
	else if (lenInterval <= 100 && lenInterval > 50) {
		sizeStartPopulation = 20;
	}
	else if (lenInterval <= 1000 && lenInterval > 100) {
		sizeStartPopulation = 50;
	}
	else {
		sizeStartPopulation = 100;
	}

	// "��������" ������,������ ����� �������� ��������� ���������
	int* rezArr = new int[(2 * sizeStartPopulation) + 1];

	// �������� ������ �����
	int* XRez = new int[(2 * sizeStartPopulation) + 1];

	// �������� ��������� �
	int* funcX = new int[sizeStartPopulation];

	// �������� Y ��� ��������� X
	int* funcY = new int[sizeStartPopulation];

	// ������������ ����
	int* Child = new int[sizeStartPopulation];

	// ������� �-��������
	string* funcBit = new string[sizeStartPopulation];

	// ������� ����
	string* childBit = new string[sizeStartPopulation + 1];

	//--------------------------------------------------------------------------------------------------
	// ���������� ��������� ���������

	if (flag == 1) {
		for (int i = 0; i < sizeStartPopulation; i++) {
			if (i == 0) {
				funcX[i] = A;
				funcY[i] = function(A);
				funcBit[i] = binary(A, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";
			}
			else if (i == 1) {
				funcX[i] = B;
				funcY[i] = function(B);
				funcBit[i] = binary(B, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";
			}
			else {
				int random = randInt(A, B);
				funcX[i] = random;
				funcY[i] = function(random);
				funcBit[i] = binary(random, B);
				cout << "---------------------------------------" << endl;
				cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
				cout << " Y" << i + 1 << " = " << funcY[i] << endl;
				cout << "---------------------------------------";

			}
		}
	}
	else
	{
		funcX = *nextArr;
		for (int i = 0; i < sizeStartPopulation; i++) {

			funcY[i] = function(funcX[i]);
			funcBit[i] = binary(funcX[i], B);
			cout << "---------------------------------------" << endl;
			cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
			cout << " Y" << i + 1 << " = " << funcY[i] << endl;
			cout << "---------------------------------------";

		}
	}
	//--------------------------------------------------------------------------------------------------
	// ����� ������� ������ � ��� ������ � ������� "�������",��� �� ���� �������� ������� ������ ����� �����
	int IndexMax = 0;
	int Max = findMinRec2(funcY, sizeStartPopulation);

	for (int i = 0; i < sizeStartPopulation; i++) {
		cout << "FuncY" << i << " " << funcY[i] << endl;
		if (funcY[i] == Max) {
			IndexMax = i;
			xMaxFunc = i;
			break;
		}
	}
	maxFunc = Max;
	cout << "MIN = " << Max << endl;
	cout << "IndexMin " << IndexMax << endl;


	//--------------------------------------------------------------------------------------------------
	// ���������� "������� ���������" ���������
	childBit = Crossover(funcBit, IndexMax, B, sizeStartPopulation);
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		cout << "ChildBit : " << i << " " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �������� ��������� 
	Mutation(childBit, B);

	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		cout << "������������ ����! " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// ��������� �� 2 -> 10 
	reBinary(Child, B, A, childBit, sizeStartPopulation); // �� ChildBit (�����) ������������ � Child(�����),��� �� �������������!
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		cout << "Child" << i << " " << Child[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �� ��������� �������� ���,��� ������ ������!
	Selection(funcX, Child, rezArr, XRez, sizeStartPopulation,2,&xMaxFunc,&maxFunc);
	cout << "maxFunc" << maxFunc << endl;
	cout << "xMaxFunc" << xMaxFunc << endl; // ������� �������
	if (flag == 1) {
		return rezArr;
	}
	else {
		*nextArr = rezArr;
	}
	
}



/*void GenMax2(int A, int B, int** YepAnotherArray) {
	
	int maxFunc, xMaxFunc; // ������� �������
	int sizeStartPopulation; //����� ��������� ���������,������ �� ���������
	int lenInterval = B - A;

	if (lenInterval <= 10) {
		sizeStartPopulation = 6;
	}
	else if (lenInterval <= 50 && lenInterval > 10) {
		sizeStartPopulation = 10;
	}
	else if (lenInterval <= 100 && lenInterval > 50) {
		sizeStartPopulation = 20;
	}
	else if (lenInterval <= 1000 && lenInterval > 100) {
		sizeStartPopulation = 50;
	}
	else {
		sizeStartPopulation = 100;
	}

	// "��������" ������,������ ����� �������� ��������� ���������
	int* rezArr = new int[(2 * sizeStartPopulation) + 1];

	// �������� ������ �����
	int* XRez = new int[(2 * sizeStartPopulation) + 1];

	// �������� ��������� �
	int* funcX = new int[sizeStartPopulation];

	funcX = *YepAnotherArray;
	// �������� Y ��� ��������� X
	int* funcY = new int[sizeStartPopulation];

	// ������������ ����
	int* Child = new int[sizeStartPopulation];

	// ������� �-��������
	string* funcBit = new string[sizeStartPopulation];

	// ������� ����
	string* childBit = new string[sizeStartPopulation + 1];

	//--------------------------------------------------------------------------------------------------
	// ���������� ��������� ���������

	for (int i = 0; i < sizeStartPopulation; i++) {

		funcY[i] = function(funcX[i]);
		funcBit[i] = binary(funcX[i], B);
		cout << "---------------------------------------" << endl;
		cout << " X" << i + 1 << " = " << funcX[i] << ",�������� ��� " << funcBit[i] << endl;
		cout << " Y" << i + 1 << " = " << funcY[i] << endl;
		cout << "---------------------------------------";

	}

	//--------------------------------------------------------------------------------------------------
	// ����� �������� ������ � ��� ������ � ������� "�������",��� �� ���� �������� ������� ������ ����� �����
	int IndexMax = 0;
	int Max = findMinRec2(funcY, sizeStartPopulation);

	for (int i = 0; i < sizeStartPopulation; i++) {
		cout << "FuncY" << i << " " << funcY[i] << endl;
		if (funcY[i] == Max) {
			IndexMax = i;
			xMaxFunc = i;
			break;
		}
	}
	maxFunc = Max;
	cout << "MIN = " << Max << endl;
	cout << "IndexMin " << IndexMax << endl;


	//--------------------------------------------------------------------------------------------------
	// ���������� "������� ���������" ���������
	childBit = Crossover(funcBit, IndexMax, B, sizeStartPopulation);
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		cout << "ChildBit : " << i << " " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �������� ��������� 
	Mutation(childBit, B);

	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//cout << "������������ ����! " << childBit[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// ��������� �� 2 -> 10 
	reBinary(Child, B, A, childBit, sizeStartPopulation); // �� ChildBit (�����) ������������ � Child(�����),��� �� �������������!
	for (int i = 0; i < sizeStartPopulation + 1; i++) {
		//childBit[i] = Crossover(funcBit, IndexMin)[i];
		//cout << "Child" << i << " " << Child[i] << endl;
	}

	//--------------------------------------------------------------------------------------------------
	// �� ��������� �������� ���,��� ������ ������!
	Selection(funcX, Child, rezArr, XRez, sizeStartPopulation, 2, &xMaxFunc, &maxFunc);
	cout << "maxFunc" << maxFunc << endl;
	cout << "xMaxFunc" << xMaxFunc << endl; // ������� �������

	*YepAnotherArray = rezArr;

}
*/



void Ext(int A, int B) {
	int userChooseMinMax;
	int lenInterval = B - A;
	int xMin, yMin, xMax, yMax;
	int* nullarr = new int[1];
	int k = 10;
	int n;
	//------------------------------------------------------------
	if (lenInterval <= 10) {
		n = 5;
	}
	else if (lenInterval <= 50 && lenInterval > 10) {
		n = 10;
	}
	else if (lenInterval <= 100 && lenInterval > 50) {
		n = 20;
	}
	else if (lenInterval <= 1000 && lenInterval > 100) {
		n = 50;
	}
	else {
		n = 100;
	}
	int* score = new int[2 * n + 1];
	int* minArr = new int[2 * n + 1];
	int* maxArr = new int[2 * n + 1];

	//----------------------------------------------------------------


	cout << "�������� �������: |1| - ����� �������, |2| - ����� �������� "; cin >> userChooseMinMax;


	if (userChooseMinMax == 1) {
		minArr = GenMin(A, B, &nullarr,1);
		int k = 10;

		while (k > 0) {

			GenMin(A, B, &minArr,0);
			k -= 1;

			cout << "----------------" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "GENMIN = " << minArr[i] << endl;
			}
			cout << "----------------" << endl;

			//int j = 0;
			for (int i = 0; i < 2 * n + 1; i++) {
				if (i == 0) {
					yMin = function(minArr[i]);
					xMin = minArr[i];
				}
				else {
					if (function(minArr[i]) < yMin) {
						yMin = function(minArr[i]);
						xMin = minArr[i];

					}

					//score[j] = xMin;
					//j += 1;
					cout << "-----------------------------------------" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "yMin " << yMin << endl;
					cout << "xMin " << xMin << endl;

				}
			}

			
		}

		cout << "������� ������� " << yMin << endl;
		cout << "�����,� ������� ����������� ������� " << xMin << endl;

	}
	else if (userChooseMinMax == 2) {
		maxArr = GenMax(A, B,&nullarr,1);
		int k = 10;
		while (k > 0) {

			//GenMin(A, B);

			//GenMin(A, B, &minArr,0);
			GenMax(A, B, &maxArr,0);
			k -= 1;

			cout << "----------------" << endl;
			for (int i = 0; i < 5; i++) {
				cout << "GENMIN = " << minArr[i] << endl;
			}
			cout << "----------------" << endl;

			//int j = 0;
			for (int i = 0; i < 2 * n + 1; i++) {
				if (i == 0) {
					yMax = function(maxArr[i]);
					xMax = maxArr[i];
				}
				else {
					if (function(maxArr[i]) > yMax) {
						yMax = function(maxArr[i]);
						xMax = maxArr[i];
					}
				}
				//score[j] = xMin;
				//j += 1;

				cout << "yMax" << yMax << endl;
				cout << "xMax " << xMax << endl;
				cout << "-----------------------------------------" << endl;
				cout << "-----------------------------------------" << endl;
			}
		}

	
		cout << "�������� ������� " << yMax << endl;
		cout << "�����,� ������� ����������� �������� " << xMax << endl;


	}
	else {
		cout << "������ �����";
	}

	delete[] minArr;
	delete[] maxArr;
	delete[] score;
	
}
	
void menu() {
	int A, B, userChoose;
	cout << "~-~-~-~-~-~-~-~-~-~-~ ������������ ��������! �������� ���! ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl;
	cout << "�������� ��������..." << endl;
	cout << "|1| ����� ����������� ������� " << endl;
	cout << "|2| ����������� ������� ������" << endl;
	cout << "|3| ���������" << endl;
	cout << "|4| ��������� ������" << endl;
	cin >> userChoose;
	if (userChoose == 1) {
		cout << "������� ������ ������� - "; cin >> A;
		cout << "������� ������ ������� - "; cin >> B; cout << endl;
		if (B > A && (B - A) >= 5) {
			Ext(A, B);
		}
		else {
			cout << "������ �����";
		}
	}
	else if (userChoose == 2) {
		int iu = 0;
	}
	else if (userChoose == 3) {
		int iu = 0;
	}
	else if (userChoose == 4) {
		int iu = 0;
	}
	else {
		int iu = 0;
	}
	
}
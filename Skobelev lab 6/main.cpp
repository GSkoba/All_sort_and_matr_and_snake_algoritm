
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime> 

using namespace std;


 int permutationsCountb, comparisonsCountb, permutationsCountsel, comparisonsCountsel,permutationsCountin , comparisonsCountin, permutationsCountshaell, comparisonsCountshaell, permutationsCountqk , comparisonsCountqk;



void printMatrix(int **arr, int N, int M);

void setValues(int **sourceArray, int *tempArray, int length, int width);

void bubbleSort(int *arr, int size, int type);

void selectionSort(int *arr, int size, int type);

void insertionSort(int *arr, int size, int type);

void shellSort(int* arr, int size, int type);

void quickSort(int *arr, int start, int finish, int type);


int main()
{

	//int permutationsCountb, comparisonsCountb, permutationsCountsel, comparisonsCountsel, permutationsCountin, comparisonsCountin, permutationsCountshaell, comparisonsCountshaell, permutationsCountqk, comparisonsCountqk;
	setlocale(LC_ALL, "Russian");

	double N, M;




	bool isInputCorrect = 0;

	srand(time(0));

	do
	{
		cin.clear();
		cin.sync();

		cout << "������� ���������� ������ ������� M x N >> ";
		cin >> N >> M;

	//	if (cin.fail() || N < 2 || M < 2 || (N - (int)N != 0) || (M - (int)M != 0))
		if (cin.fail() ||(N - (int)N != 0) || (M - (int)M != 0))
		{
			cout << "�� ����� �� ���������� ��������, ���������� �����. \n";
		}
		else
		{
			isInputCorrect = 1;
		}

	} while (!isInputCorrect);

	int BY_DESCENDING = -1;
	int length = (int)N;
	int width = (int)M;

	// ��������� ������ ��� ��������� �������
	int **sourceArray = new int *[length];
	for (int i = 0; i < length; i++)
		sourceArray[i] = new int[width];

	//��������� ������ ��� �������, ������� ����� ����������� ��������� 
	int **bubbleArray = new int*[length];
	for (int i(0); i < length; i++)
		bubbleArray[i] = new int[width];

	////��������� ������ ��� �������, ������� ����� ����������� ��������
	int **selleArray = new int*[length];
	for (int i(0); i < length; i++)
		selleArray[i] = new int[width];

	//��������� ������ ��� �������, ������� ����� ����������� �������� 
	int **inArray = new int*[length];
	for (int i(0); i < length; i++)
		inArray[i] = new int[width];

	//��������� ������ ��� �������, ������� ����� ����������� Shell 
	int **shellArray = new int*[length];
	for (int i(0); i < length; i++)
		shellArray[i] = new int[width];

	//��������� ������ ��� �������, ������� ����� ����������� qk 
	int **qkArray = new int*[length];
	for (int i(0); i < length; i++)
		qkArray[i] = new int[width];

	//���������� ���� �������� ���������� ����������
	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		sourceArray[i][j] = shellArray[i][j] = qkArray[i][j] = inArray[i][j] = selleArray[i][j]
		= bubbleArray[i][j] = rand() % 100;



	cout << "��������� �������: \n";
	printMatrix(sourceArray, length, width);

	// ��������� ������ ��� ����������� ������ 
	int *tempArray = new int[length*width];


	//����� ���� ���������� 




	// ��������� ����������� ������� ���������� �������
	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		tempArray[i*width + j] = bubbleArray[i][j];




	//unsigned int pc = 0;	//���������� ������������ 
	//	unsigned int cc = 0;	//���������� ���������� 

	bubbleSort(tempArray, length*width, BY_DESCENDING);

	// ��������� ��������������� ��������� � �������  
	setValues(bubbleArray, tempArray, length, width);

	cout << "\n������ ����� ���������� ��������� : \n";
	printMatrix(bubbleArray, length, width);
	cout << "\n";




	// ��������� ����������� ������� ���������� �������
	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		tempArray[i*width + j] = selleArray[i][j];




	//unsigned int pc = 0;	//���������� ������������ 
	//unsigned int cc = 0;	//���������� ���������� 

	selectionSort(tempArray, length*width, BY_DESCENDING);

	// ��������� ��������������� ��������� � ������ 
	setValues(selleArray, tempArray, length, width);

	cout << "\n������ ����� ���������� ������� : \n";
	printMatrix(selleArray, length, width);
	cout << "\n";




	// ��������� ����������� ������� ���������� �������
	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		tempArray[i*width + j] = inArray[i][j];




	//unsigned int pc = 0;	//���������� ������������ 
	//unsigned int cc = 0;	//���������� ���������� 

	insertionSort(tempArray, length*width, BY_DESCENDING);

	// ��������� ��������������� ��������� � ������ 
	setValues(inArray, tempArray, length, width);

	cout << "\n������ ����� ���������� ������� : \n";
	printMatrix(inArray, length, width);
	cout << "\n";




	// ��������� ����������� ������� ���������� �������
	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		tempArray[i*width + j] = qkArray[i][j];




	//unsigned int pc = 0;	 
	//unsigned int cc = 0;	
	//void quickSort(int *arr, int start, int finish, int type);
	quickSort(tempArray,0, length*width-1, BY_DESCENDING);


	setValues(qkArray, tempArray, length, width);

	cout << "\n������ ����� ���������� ������� : \n";
	printMatrix(qkArray, length, width);
	cout << "\n";



	for (int i = 0; i < length; i++)
	for (int j = 0; j < width; j++)
		tempArray[i*width + j] = shellArray[i][j];




	//unsigned int pc = 0;	 
	//unsigned int cc = 0;	

	shellSort(tempArray, length*width, BY_DESCENDING);


	setValues(shellArray, tempArray, length, width);

	cout << "\n������ ����� ���������� ���� : \n";
	printMatrix(shellArray, length, width);


	cout << endl;
	cout << "\n��������� ����������:\n"
		<< "| ��� ����������   | " << "���������� ������������ | " << "���������� ��������� |\n"
		<< "|  ������         |" << std::setw(24) << permutationsCountb << " | " << std::setw(20) << comparisonsCountb << " | \n"
		<< "|  �������         |" << std::setw(24) << permutationsCountsel << " | " << std::setw(20) << comparisonsCountsel << " | \n"
		<< "|  �������         |" << std::setw(24) << permutationsCountin << " | " << std::setw(20) << comparisonsCountin << " | \n"
		<< "|  �������         |" << std::setw(24) << permutationsCountqk << " | " << std::setw(20) << comparisonsCountqk << " | \n"
		<< "|  ����            |" << std::setw(24) << comparisonsCountshaell << " | " << std::setw(20) << comparisonsCountshaell << " | \n";

	// �������� ��������, ������� ������ 
	for (int i = 0; i < length; i++)
		delete[] sourceArray[i];
	delete[] sourceArray;

	for (int i = 0; i < length; i++)
		delete[] shellArray[i];
	delete[] shellArray;

	for (int i = 0; i < length; i++)
		delete[] inArray[i];
	delete[] inArray;

	for (int i = 0; i < length; i++)
		delete[] selleArray[i];
	delete[] selleArray;

	for (int i = 0; i < length; i++)
		delete[] bubbleArray[i];
	delete[] bubbleArray;

	for (int i = 0; i < length; i++)
		delete[] qkArray[i];
	delete[] qkArray;

	delete[] tempArray;

	system("pause");
	return 0;
}


void printMatrix(int **arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}


void setValues(int **sourceArray, int *tempArray, int length, int width)
{
	int tempArrayCounter = 0;

	int iUp = 0;
	int iDown = 0;
	int jLeft = 0;
	int jRight = 0;

	while (true)
	{
		for (int j = jLeft; j < width - jRight; j++)
		{
			sourceArray[iUp][j] = tempArray[tempArrayCounter];
			tempArrayCounter++;
		}

		iUp++;

		if (width - jLeft == jRight)
			break;
		if (length - iDown == iUp)
			break;

		for (int i = iUp; i < length - iDown; i++)
		{
			sourceArray[i][width - jRight - 1] = tempArray[tempArrayCounter];
			tempArrayCounter++;
		}

		jRight++;

		if (width - jLeft == jRight)
			break;
		if (length - iDown == iUp)
			break;

		for (int j = width - jRight - 1; j >= jLeft; j--)
		{
			sourceArray[length - iDown - 1][j] = tempArray[tempArrayCounter];
			tempArrayCounter++;
		}

		iDown++;

		if (width - jLeft == jRight)
			break;
		if (length - iDown == iUp)
			break;

		for (int i = length - iDown - 1; i >= iUp; i--)
		{
			sourceArray[i][jLeft] = tempArray[tempArrayCounter];
			tempArrayCounter++;
		}

		jLeft++;


		if (width - jLeft == jRight)
			break;
		if (length - iDown == iUp)
			break;
	}
}


void bubbleSort(int *arr, int size,  int type)
{
	bool sorted = false;

	::permutationsCountb = 0;

	::comparisonsCountb = 0;

	while (!sorted)
	{
		sorted = true;

		for (int i = 0; i < size - 1; i++)
		{
			if (++::comparisonsCountb && type*arr[i] > type*arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				sorted = false;
				::permutationsCountb++;
			}
		}
	}
}


void selectionSort(int *arr, int size,  int type)
{
	int minValue;
	int minIndex;

	::permutationsCountsel = 0;

	::comparisonsCountsel = 0;

	for (int i = 0; i < size - 1; i++)
	{
		minValue = arr[i];
		minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (++::comparisonsCountsel && type*arr[j] < type*minValue)
			{
				minValue = arr[j];
				minIndex = j;
				::permutationsCountsel++;
			}
		}
		arr[minIndex] = arr[i];
		arr[i] = minValue;
	}
}

void insertionSort(int *arr, int size,  int type)
{
	int sortedPartIndex = 1;

	//permutationsCountin = 0;

	//comparisonsCountin = 0;

	for (int i = sortedPartIndex; i < size; i++)
	{
		for (int j = 0; j < sortedPartIndex; j++)
		{
			if (++comparisonsCountin && type*arr[i] < type*arr[j])
			{

				swap(arr[i], arr[j]);

				permutationsCountin++;
			}
		}
		sortedPartIndex++;
	}
}

void shellSort(int* arr, int size,  int type)
{
	int i, j, d;

	d = size;
	d = d / 2;

	permutationsCountshaell = 0;

	comparisonsCountshaell = 0;

	while (d > 0)
	{
		for (i = 0; i < size - d; i++)
		{
			j = i;

			while (++::comparisonsCountshaell && j >= 0 && type*arr[j] > type*arr[j + d])
			{
				swap(arr[j], arr[j + d]);
				::permutationsCountshaell++;
				j--;
			}
		}

		d = d / 2;
	}
}


void quickSort(int *arr, int start, int finish,  int type)
{
	permutationsCountqk = 0;

	comparisonsCountqk = 0;

	if (finish - start == 0)
		return;

	int l = start, r = finish;

	int piv = arr[(l + r) / 2];

	while (l <= r)
	{
		while (++::comparisonsCountqk && type*arr[l] < type*piv)
		{
			l++;
		}
		while (++::comparisonsCountqk && type*arr[r] > type*piv)
		{
			r--;
		}

		if (l <= r)
		{
			swap(arr[l++], arr[r--]);
			::permutationsCountqk++;
		}
	}
	if (start < r)
	{
		unsigned int tempPermutationCount = ::permutationsCountqk;
		unsigned int tempComparisonsCount = ::comparisonsCountqk;
		quickSort(arr, start, r,  type);
		::permutationsCountqk += tempPermutationCount;
		::comparisonsCountqk += tempComparisonsCount;
	}
	if (finish > l)
	{
		unsigned int tempPermutationCount = ::permutationsCountqk;
		unsigned int tempComparisonsCount = ::comparisonsCountqk;
		quickSort(arr, l, finish, type);
		::permutationsCountqk += tempPermutationCount;
		::comparisonsCountqk += tempComparisonsCount;
	}
}

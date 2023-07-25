#include "AIRS.h"

AIRS::AIRS()
{
	strcpy_s(trainNumber, "trXXX");
	strcpy_s(departureTime, "XX:XX");
	strcpy_s(destination, "none");
}

AIRS::AIRS(const char* train, const char* time, const char* dest)
{
	strcpy_s(trainNumber, sizeof(trainNumber), train);
	strcpy_s(departureTime, sizeof(departureTime), time);
	strcpy_s(destination, sizeof(destination), dest);
}

void AIRS::input() //хотел добавить throw при неправильном вводе, но он почему-то не работает, возможно связанно с cin.getline
{
	system("cls"); 

	cout << "Enter train number: ";
	cin.getline(trainNumber, sizeof(trainNumber));

	cout << "Enter time of departure: ";
	cin.getline(departureTime, sizeof(departureTime));

	cout << "Enter destination station: ";
	cin.getline(destination, sizeof(destination));
}


void AIRS::output() const
{
	cout << "-------------------------" << endl;
	cout << "train: " << trainNumber << endl;
	cout << "time : " << departureTime << endl;
	cout << "dest.: " << destination << endl;
	cout << "-------------------------" << endl;
}

void AIRS::add(vector<AIRS>& trains)
{
	AIRS train;

	train.input();

	trains.push_back(train);
}

void AIRS::show(vector<AIRS>& trains) const
{
	for (auto train : trains)
	{
		train.output();
	}
}

void AIRS::save(const string filename, vector<AIRS>& trains) const
{
    ofstream save(filename, ios::binary);

    if (!save)
    {
        const char error[40] = "Error: Cannot open file for writing.";
        throw error;
    }

    for (const AIRS& train : trains)
    {
        save.write(train.trainNumber, sizeof(train.trainNumber));
        save.write(train.departureTime, sizeof(train.departureTime));
        save.write(train.destination, sizeof(train.destination));
    }

    cout << "Data saved to " << filename << " successfully." << endl;
    save.close();
}

void AIRS::load(const string filename, vector<AIRS>& trains)
{
    ifstream load(filename, ios::binary);

    if (!load)
    {
        const char error[40] = "Error: Cannot open file for reading.";
        throw error;
    }

    while (!load.eof())
    {
        load.read(trainNumber, sizeof(trainNumber));
        load.read(departureTime, sizeof(departureTime));
        load.read(destination, sizeof(destination));

        if (!load.fail())
        {
            AIRS train(trainNumber, departureTime, destination);
            trains.push_back(train);
        }
    }

    cout << "Data loaded from '" << filename << "' successfully." << endl;
    load.close();
}


#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{
}

int count = 0;
void Model::tick()
{
	count++;
	bool ledStatus[27] = { false, };

	if (count == 1000)
	{
		count = 0;
		for (int i = 0; i < 27; i++)
		{
			ledStatus[i] ^= true;
		}
		modelListener->updateLEDState(ledStatus);

	}
}

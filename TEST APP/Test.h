#pragma once
class Test
{

protected:
	int val, min, sec;

public:

	virtual int HoursToMinutes();

	bool operator==(Test other) const
	{
		if (this->val == other.val && this->min == other.min && this->sec == other.sec)
			return true;
		return false;
	}
	Test();
	Test(int x, int y, int z);
	~Test();
};


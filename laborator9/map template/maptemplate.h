#pragma once

template<class T1, class T2>
struct elemente
{
	T1 key;
	T2 value;
	int index;
};

template<class T1, class T2>
class harta {
private:
	elemente<T1, T2> items[256];
	int nrElemente;
public:
	harta<T1, T2>() : nrElemente(0), items{0, 0, 0} {};
	T2& operator[](T1 key);
	void set(T1 key, T2 value);
	bool Get(const T1& key, T2& value);
	int count();
	void clear();
	bool Delete(const T1& key);
	const elemente<T1, T2>* begin();
	const elemente<T1, T2>* end();
};

template<class T1, class T2>
T2& harta<T1, T2>::operator[](T1 key)
{
	for (int i = 0; i < nrElemente; i++)
	{
		if (this->items[i].key == key) return this->items[i].value;
	}
	this->items[nrElemente] = { key, 0, this->nrElemente };
	this->nrElemente++;
	return this->items[nrElemente - 1].value;
}

template<class T1, class T2>
void harta<T1, T2>::set(T1 key, T2 value)
{
	int ok = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (items[i].key == key)
		{
			this->items[i].value = value;
			ok = 1;
		}
	}
	if (!ok)
	{
		this->items[nrElemente] = { key, value, this->nrElemente };
		this->nrElemente++;
 	}
}

template<class T1, class T2>
bool harta<T1, T2>::Get(const T1& key, T2& value)
{
	if (items[key].value)
	{
		value = items[key].value;
		return true;
	}
	return false;
}

template<class T1, class T2>
int harta<T1, T2>::count()
{
	return this->nrElemente;
}

template<class T1, class T2>
void harta<T1, T2>::clear()
{
	for(int i = 0; i < nrElemente; i++)
		items[i] = {0, 0, 0};
	nrElemente = 0;
}

template<class T1, class T2>
inline bool harta<T1, T2>::Delete(const T1& key)
{
	for (int i = 0; i < this->nrElemente; i++)
	{
		if (this->items[i].key == key)
		{
			for (int j = i; j < this->nrElemente - 1; j++)
			{
				this->items[j] = this->items[j + 1];
			}
			items[this->nrElemente] = { 0, 0, 0 };
			return true;
		}
	}
	return false;
}

template<class T1, class T2>
const elemente<T1, T2>* harta<T1, T2>::begin()
{
	return &(this->items[0]);
}

template<class T1, class T2>
const elemente<T1, T2>* harta<T1, T2>::end()
{
	return &(this->items[this->nrElemente]);
}
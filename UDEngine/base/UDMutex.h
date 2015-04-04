#ifndef UDMUTEX_H
#define UDMUTEX_H
#include <windows.h>
#include "UDNonCopyable.hpp"

//������
class UDMutexLock : private UDNonCopyable
{
public:
	UDMutexLock();
	~UDMutexLock();

	virtual void lock();
	virtual void unLock();

	bool isLocked() const { return m_isLocked; }

private:
	HANDLE m_mutex;
	bool m_isLocked;
};

// ����C++���ԣ�ʵ���Զ���������
class AutoLock : private UDNonCopyable
{
public:
	AutoLock(UDMutexLock &mutex);
	~AutoLock();

private:
	UDMutexLock &m_mutexLock;
};

#endif	//UDMUTEX_H
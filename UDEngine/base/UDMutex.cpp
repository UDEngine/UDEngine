#include "UDMutex.h"
#include <assert.h>

UDMutexLock::UDMutexLock()
	: m_isLocked(false)
{
	m_mutex = ::CreateMutex(NULL, FALSE, NULL);
}

UDMutexLock::~UDMutexLock()
{
	assert(!isLocked());
	::CloseHandle(m_mutex);
}

void UDMutexLock::lock()
{
	WaitForSingleObject(m_mutex, INFINITE);
	m_isLocked = true;
}

void UDMutexLock::unLock()
{
	m_isLocked = false;
	::ReleaseMutex(m_mutex);
}

AutoLock::AutoLock(UDMutexLock &mutex)
	: m_mutexLock(mutex)
{
	m_mutexLock.lock();
}

AutoLock::~AutoLock()
{
	m_mutexLock.unLock();
}

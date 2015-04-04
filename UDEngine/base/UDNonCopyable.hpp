#ifndef UDNONCOPYABLE_HPP
#define UDNONCOPYABLE_HPP

//禁用拷贝构造和赋值
class UDNonCopyable
{
protected:
	UDNonCopyable() {	}
	~UDNonCopyable(){	}
private:
	UDNonCopyable(const UDNonCopyable &);
	void operator = (const UDNonCopyable &);
};

#endif	//UDENGINE_UNCOPYABLE_HPP
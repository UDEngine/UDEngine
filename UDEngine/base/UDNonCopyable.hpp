#ifndef UDNONCOPYABLE_HPP
#define UDNONCOPYABLE_HPP

//���ÿ�������͸�ֵ
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
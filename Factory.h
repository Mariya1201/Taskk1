#ifndef __FACTORY_HPP_INCLUDED__
#define __FACTORY_HPP_INCLUDED__

//#include "CString"
//#include "CString0.h"
//#include "CString1.h"
#include "headers.h"
class Factory
{
public:
	virtual CString* create() = 0;
	virtual CString* create(string _fileName, const char* _data, int _dataSize) = 0;
	virtual CString* create(const CString& other) = 0;
};

class Factory_hori0 : public Factory
{
public:
	CString* create() override { return new CString0(); }
	CString* create(string _fileName, const char* _data, int _dataSize) override { return new CString0(_file_name, _data, _dataSize); }
	CString* create(const CString& other) override { return new CString0(other); }
};

class Factory_vert1 : public Factory
{
public:
	CString* create() override { return new CString1(); }
	CString* create(string _fileName, const char* _data, int _dataSize) override { return new CString1(_file_name, _data, _dataSize)); }
	CString* create(const CString& other) override { return new CString1(other); }
};


#endif #pragma once

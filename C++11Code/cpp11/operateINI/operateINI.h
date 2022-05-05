/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-14 16:35:47
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>
#include <string>

 
//INI文件结点
class ININode
{
public:
	ININode(std::string root, std::string key, std::string value)
	{
		this->root = root;
		this->key = key;
		this->value = value;
	}
	std::string root;
	std::string key;
	std::string value;
};
 
//键值对
class SubNode
{
public:
	void InsertElement(std::string key, std::string value)
	{
		sub_node.insert(std::pair<std::string, std::string>(key, value));
	}
	std::map<std::string, std::string> sub_node;
};
 
//INI文件操作类
class CMyINI
{
public:
	CMyINI();
	~CMyINI();
 
public:
	int ReadINI(std::string path);													//读取INI文件
	std::string GetValue(std::string root, std::string key);									//由根结点和键获取值
	std::vector<ININode>::size_type GetSize(){ return map_ini.size(); }				//获取INI文件的结点数
	void SetValue(std::string root, std::string key, std::string value);	//设置根结点和键获取值
	int WriteINI(std::string path);			//写入INI文件
	void Clear(){ map_ini.clear(); }	//清空
	void Travel();						//遍历打印INI文件
private:
	std::map<std::string, SubNode> map_ini;		//INI文件内容的存储变量
};
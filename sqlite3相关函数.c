
int sqlite3_open(const char *filename, sqlite3 **ppDb)
/*********************************************************************************  
* Description：  打开数据 （不存在则创建）
* Input:         filename：数据库路径名  ppDb：代指打开的数据库（打开的数据库句柄）
* Return:        成功返回 SQLITE_OK 失败返回错误码
* Others:        不存在，则创建
**********************************************************************************/

int sqlite3_close(sqlite3 *ppDb);
/*********************************************************************************  
* Description：  关闭数据库
* Input:         ppDb:为刚才使用sqlite3_open打开的数据库链接
* Return:        
* Others:       
**********************************************************************************/

int sqlite3_exec(sqlite3* ppDb, const char *sql, sqlite_callback, void *data, char **errmsg)
/*********************************************************************************  
* Description：  执行sql语句
* Input:         ppDb:为刚才使用sqlite3_open打开的数据库链接
				 sql: sql语句
				 sqlite_callback:回调函数 用于查询
				 data: 回调函数的参数
				 errmsg：返回的错误信息
* Return:        成功返回0 失败返回错误码
* Others:       
**********************************************************************************/
typedef  int (*sqlite3_callback)(void *para, int f_num, char **f_value, char **f_name);
//注意sqlite3_callback类型为 函数指针
/*
 *para：	传递给回调函数的参数
 *f_num：	记录中包含的字段数目
 *f_value：	包含每个字段值的指针数组
 *f_name：	包含每个字段名称的指针数组
 */

int   sqlite3_get_table(sqlite3 *ppDb, const  char  *sql,  char ***resultp,  int*nrow,  int *ncolumn, char **errmsg);
/*********************************************************************************  
* Description：  执行sql语句
* Input:         ppDb:为刚才使用sqlite3_open打开的数据库链接
				 sql: sql语句
*                resultp:查询的结果 例如：resultp[0]、resultp[1]、resultp[2]、resultp[3]
				 nrow: 查询到的记录数目
				 ncolumn：字段数目
				 errmsg：返回的错误信息
  Return:        成功返回0 失败返回错误码
* Others:       
**********************************************************************************/

const  char  *sqlite3_errmg(sqlite3 *db);
/*********************************************************************************  
* Description：  错误解析
* Input:         db:为刚才使用sqlite3_open打开的数据库链接
				 
* Return:        返回的错误信息
* Others:       
**********************************************************************************/

void sqlite3_free(char *errmsg);         
/*********************************************************************************  
* Description：  释放错误解析空间
* Input:         errmsg：错误信息的地址
* Return:        
* Others:       
**********************************************************************************/


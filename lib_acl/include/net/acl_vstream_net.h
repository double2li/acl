#ifndef __ACL_VSTREAM_NET_INCLUDE_H__
#define __ACL_VSTREAM_NET_INCLUDE_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "stdlib/acl_define.h"
#include "stdlib/acl_vstream.h"

/**
 * 监听某个地址（对于UNIX，还可以监听域套接字）
 * @param addr {const char*} 监听地址,
 *  如：127.0.0.1:80; 或域套接字(UNIX平台) 如：/tmp/test.sock
 * @param qlen {int} 监听队列的长度
 * @param block_mode {int} 是阻塞监听还是非阻塞监听, ACL_BLOCKING: 阻塞模式,
 *  ACL_NON_BLOCKING: 非阻塞模式
 * @param bufsize {int} 接收的新的客户端套接字的IO缓冲区大小
 * @param rw_timeout {int} 接收的新的客户端套接字的IO读写超时时间，单位为秒
 * @return {ACL_VSTREAM*} 监听流指针
 */
ACL_API ACL_VSTREAM *acl_vstream_listen_ex(const char *addr, int qlen,
		int block_mode, int io_bufsize, int rw_timeout);

/**
 * 监听某个地址（对于UNIX，还可以监听域套接字）
 * @param addr {const char*} 监听地址
 *  如：127.0.0.1:80, 或域套接字, 如：/tmp/test.sock
 * @param qlen {int} 监听队列的长度
 * @return {ACL_VSTREAM*} 监听流指针
 */
ACL_API ACL_VSTREAM *acl_vstream_listen(const char *addr, int qlen);

/**
 * 从监听流中接收一个客户端连接流
 * @param listen_stream {ACL_VSTREAM*} 监听流
 * @param client_stream {ACL_VSTREAM*} 可重复利用的 ACL_VSTREAM 结构，
 *  如果为空则内部产生一个新的 ACL_VSTREAM 流，否则复用该结构空间
 * @param ipbuf {char*} 如果不为空则用来存储客户端的IP地址
 * @param bsize {int} 如果 ipbuf 不为空，则表示 ipbuf 的空间大小
 * @return {ACL_VSTREAM*} 如果不为空则表示新接收的客户端流
 */
ACL_API ACL_VSTREAM *acl_vstream_accept_ex(ACL_VSTREAM *listen_stream,
		ACL_VSTREAM *client_stream, char *ipbuf, int bsize);

/**
 * 从监听流中接收一个客户端连接流
 * @param listen_stream {ACL_VSTREAM*} 监听流
 * @param ipbuf {char*} 如果不为空则用来存储客户端的IP地址
 * @param bsize {int} 如果 ipbuf 不为空，则表示 ipbuf 的空间大小
 * @return {ACL_VSTREAM*} 如果不为空则表示新接收的客户端流
 */
ACL_API ACL_VSTREAM *acl_vstream_accept(ACL_VSTREAM *listen_stream,
		char *ipbuf, int bsize);

/**
 * 远程连接服务器
 * @param addr {const char*} 服务器地址, 如果连接一个域套接口服务器(仅UNIX平台),
 *  域套接地址：/tmp/test.sock; 如果连接一个TCP服务器，则地址格式为:
 *  [${local_ip}@]${remote_addr}, 如: 60.28.250.199@www.sina.com:80, 意思是绑定本的
 *  网卡地址为: 60.28.250.199, 远程连接 www.sina.com 的 80 端口, 如果由OS自动绑定本地
 *  IP 地址，则可以写为：www.sina.com:80
 * @param block_mode {int} 阻塞连接还是非阻塞连接，ACL_BLOCKING, ACL_NON_BLOCKING
 * @param conn_timeout {int} 连接超时时间(秒)
 * @param rw_timeout {int} 连接流成功后的读写超时时间，单位为秒
 * @param bufsize {int} 连接流成功后的缓冲区大小
 * @param errorp {int*} 如果不为空，则存储连接失败后的错误号
 * @return {ACL_VSTREAM*} 如果不为空，则表示连接成功后的数据流
 */
ACL_API ACL_VSTREAM *acl_vstream_connect_ex(const char *addr, int block_mode,
		int conn_timeout, int rw_timeout, int bufsize, int *errorp);

/**
 * 远程连接服务器
 * @param addr {const char*} 服务器地址，格式如：127.0.0.1，
 *  或 域套接地址：/tmp/test.sock
 * @param block_mode {int} 阻塞连接还是非阻塞连接，ACL_BLOCKING, ACL_NON_BLOCKING
 * @param connect_timeout {int} 连接超时时间(秒)
 * @param rw_timeout {int} 连接流成功后的读写超时时间，单位为秒
 * @param rw_bufsize {int} 连接流成功后的缓冲区大小
 * @return {ACL_VSTREAM*} 如果不为空，则表示连接成功后的数据流
 */
ACL_API ACL_VSTREAM *acl_vstream_connect(const char *addr, int block_mode,
		int connect_timeout, int rw_timeout, int rw_bufsize);

#ifdef __cplusplus
}
#endif
#endif


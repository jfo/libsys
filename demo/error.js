const libsys = require('..');

const STDOUT = 1;
const isMac = process.platform === 'darwin';
const SYS_write = isMac ? 0x0000004 : 1;

const buf = Buffer.from('Hello world....\n');

const res = libsys.syscall(0x0000004, STDOUT, buf, buf.length);
console.log('res', res);

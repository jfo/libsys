const addon = require('../build/Release/sys.node');
const rax = require('ass-js/lib/x86/operand').rax;
const Code = require('ass-js/lib/x86/x64/code').Code;

const isMac = process.platform === 'darwin';
const SYS_mmap = isMac ? 197 : 9;

// Allocate executable memory, returns `ArrayBuffer`.
function alloc(size) {
  const flags = 2 /* MAP_PRIVATE */ | (isMac ? 4096 : 32 /* MAP_ANONYMOUS */);
  const protnum = 1 | 2 | 4; // Read, write and execute;
  const addr = addon.syscall64(SYS_mmap, 0, size, protnum, flags, -1, 0);
  return addon.malloc(addr, size);
}

describe('.syscall()', function() {
    it('Writes buffer to STDOUT', function() {
        var str = 'Hello world, hell yeah!';
        var buf = new Buffer(str + '\n');
        var SYS_write = process.platform === 'linux' ? 1 : 0x2000004;
        var res = addon.syscall(SYS_write, 1, buf, buf.length);
        expect(res).toBe(buf.length);
    });
});

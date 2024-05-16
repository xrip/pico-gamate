//
// Created by xrip on 16.05.2024.
//

#ifndef GAMATE_BIOS_H
#define GAMATE_BIOS_H
alignas(4) uint8_t BIOS[4096] = { 0x4c, 0x01, 0xf3, 0x4c, 0xe0, 0xf2, 0x4c, 0xeb, 0xf2, 0x4c, 0xf6, 0xf2, 0x4c, 0x90, 0xf5, 0x4c,
                                  0x67, 0xfb, 0x4c, 0x1d, 0xf3, 0x4c, 0xc7, 0xf5, 0x4c, 0xae, 0xf3, 0x4c, 0xf7, 0xf4, 0x4c, 0x7b,
                                  0xf4, 0x4c, 0x4a, 0xf5, 0x4c, 0x1a, 0xf6, 0x4c, 0x2f, 0xf6, 0x4c, 0x00, 0xff, 0x4c, 0x09, 0xff,
                                  0x4c, 0x79, 0xfb, 0x4c, 0x42, 0xff, 0x4c, 0xa9, 0xfb, 0xa9, 0x00, 0x85, 0x16, 0x85, 0x17, 0x85,
                                  0x15, 0xa5, 0x16, 0x8d, 0x02, 0x50, 0xa5, 0x17, 0x8d, 0x03, 0x50, 0x20, 0x90, 0xf5, 0xa9, 0xb8,
                                  0x85, 0x00, 0x85, 0x02, 0xa9, 0xf1, 0x85, 0x01, 0x85, 0x03, 0xa9, 0x58, 0x85, 0x1c, 0xa9, 0x10,
                                  0x85, 0x1d, 0xa2, 0x20, 0xa0, 0x90, 0x20, 0xc7, 0xf5, 0xa0, 0x00, 0x20, 0xeb, 0xf2, 0x8c, 0x03,
                                  0x50, 0xc8, 0xc0, 0x60, 0x90, 0xf5, 0x20, 0xf6, 0xf2, 0xa9, 0x06, 0x85, 0x21, 0xa9, 0x10, 0x85,
                                  0x00, 0x85, 0x02, 0xa9, 0xf1, 0x85, 0x01, 0x85, 0x03, 0xa9, 0x38, 0x85, 0x1c, 0xa9, 0x18, 0x85,
                                  0x1d, 0xa2, 0x30, 0xa0, 0xa4, 0x20, 0xc7, 0xf5, 0xa9, 0x68, 0x85, 0x00, 0x85, 0x02, 0xa9, 0xf2,
                                  0x85, 0x01, 0x85, 0x03, 0xa9, 0x08, 0x85, 0x1c, 0xa9, 0x08, 0x85, 0x1d, 0xa2, 0x68, 0xa0, 0xb4,
                                  0x20, 0xc7, 0xf5, 0xa9, 0x70, 0x85, 0x00, 0x85, 0x02, 0xa9, 0xf2, 0x85, 0x01, 0x85, 0x03, 0xa9,
                                  0x50, 0x85, 0x1c, 0xa9, 0x08, 0x85, 0x1d, 0xa2, 0x28, 0xa0, 0xbe, 0x20, 0xc7, 0xf5, 0xc6, 0x21,
                                  0xf0, 0x2b, 0x20, 0xf6, 0xf2, 0xa9, 0x58, 0x85, 0x1c, 0xa9, 0x28, 0x85, 0x1d, 0xa2, 0x20, 0xa0,
                                  0xa4, 0xa9, 0x00, 0x20, 0x00, 0xff, 0xa9, 0x58, 0x85, 0x1c, 0xa9, 0x28, 0x85, 0x1d, 0xa2, 0x20,
                                  0xa0, 0xa4, 0xa9, 0x00, 0x20, 0x09, 0xff, 0x20, 0xf6, 0xf2, 0x4c, 0x7d, 0xf0, 0xa0, 0x06, 0x20,
                                  0xf6, 0xf2, 0x88, 0x10, 0xfa, 0xa9, 0x01, 0x85, 0x0c, 0xa9, 0xff, 0x85, 0x0a, 0x4c, 0x20, 0x60,
                                  0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
                                  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x87, 0x80, 0x83,
                                  0x80, 0x87, 0x80, 0xff, 0x80, 0xff, 0x80, 0x87, 0x80, 0x83, 0x80, 0x87, 0x80, 0xff, 0x80, 0xff,
                                  0x00, 0x81, 0x01, 0xe1, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0xc0, 0x00, 0xf0, 0x00, 0xf8,
                                  0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf3, 0x03, 0xc3, 0x00, 0xff, 0xf8, 0xff, 0x78, 0x7f, 0x78, 0x7f,
                                  0x78, 0x7f, 0x78, 0x7f, 0x78, 0x7f, 0x78, 0x7f, 0x78, 0x7f, 0x78, 0x7f, 0x78, 0xff, 0xf8, 0xff,
                                  0x00, 0xe7, 0x07, 0xe7, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80,
                                  0x00, 0x80, 0x00, 0x80, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0xff, 0xfc, 0xff, 0x3c, 0x3f, 0x3c, 0x3f,
                                  0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f, 0x3c, 0x3f,
                                  0x00, 0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0,
                                  0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x38, 0x70, 0x70,
                                  0xe0, 0xe0, 0xe0, 0xe0, 0x70, 0x70, 0x3e, 0x1f, 0x00, 0x00, 0x00, 0xe8, 0x38, 0x18, 0x08, 0x00,
                                  0x00, 0x00, 0x7c, 0x38, 0x38, 0x38, 0xf9, 0xbb, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x0d, 0x09,
                                  0x19, 0x30, 0x3f, 0x60, 0xc0, 0xc0, 0x80, 0xc1, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0x81, 0x81,
                                  0xc1, 0xc1, 0xc1, 0xc3, 0xc2, 0xe2, 0xe2, 0xf7, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0x60,
                                  0x61, 0x71, 0x33, 0x34, 0x34, 0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x38, 0x70, 0x70, 0xf0, 0xb0,
                                  0xb0, 0x30, 0x70, 0x70, 0x61, 0x61, 0xe3, 0xf7, 0x00, 0x00, 0x00, 0x06, 0x06, 0x0f, 0x1b, 0x13,
                                  0x33, 0x61, 0x7f, 0xc1, 0x81, 0x81, 0x01, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x31, 0x63, 0x03, 0x03,
                                  0x83, 0x83, 0x87, 0x87, 0x86, 0xc6, 0xc6, 0xef, 0x00, 0x00, 0x00, 0xfb, 0x99, 0x89, 0x81, 0x01,
                                  0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x00, 0xff, 0xc3, 0xc0, 0x84, 0x84,
                                  0x8c, 0xf8, 0x88, 0x00, 0x03, 0x06, 0x06, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
                                  0x00, 0x00, 0x00, 0xf1, 0x5b, 0x5f, 0x55, 0x51, 0x3c, 0x42, 0xb9, 0xa5, 0xb9, 0xa5, 0x42, 0x3c,
                                  0x00, 0x38, 0x44, 0xba, 0xa2, 0xba, 0x44, 0x38, 0x00, 0x00, 0xf8, 0xcc, 0xf8, 0xcc, 0xcc, 0xf8,
                                  0x00, 0x00, 0x78, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, 0xfc, 0x30, 0x30, 0x30, 0x30, 0x30,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xc0, 0xc0, 0xcc, 0x78,
                                  0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xf8, 0xd0, 0xcc,
                                  0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xf8, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
                                  0x00, 0x38, 0x44, 0xba, 0xa2, 0xba, 0x44, 0x38, 0x3f, 0x19, 0x19, 0x1f, 0x19, 0x19, 0x19, 0x3f,
                                  0x3e, 0x9c, 0x9c, 0x1c, 0x9c, 0x9c, 0x9c, 0x3e, 0xfe, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
                                  0xa5, 0x0b, 0xc9, 0x08, 0x90, 0xfa, 0xa9, 0x00, 0x85, 0x0b, 0x60, 0xa5, 0x0b, 0xc9, 0x05, 0x90,
                                  0xfa, 0xa9, 0x00, 0x85, 0x0b, 0x60, 0xa5, 0x0b, 0xc9, 0x18, 0x90, 0xfa, 0xa9, 0x00, 0x85, 0x0b,
                                  0x60, 0xa9, 0xc0, 0x85, 0x00, 0x85, 0x02, 0xa9, 0xf2, 0x85, 0x01, 0x85, 0x03, 0xa9, 0x20, 0x85,
                                  0x1c, 0xa9, 0x08, 0x85, 0x1d, 0xa2, 0x40, 0xa0, 0x8c, 0x20, 0xc7, 0xf5, 0x60, 0x8a, 0x4a, 0x4a,
                                  0x4a, 0x09, 0x80, 0x85, 0x18, 0x84, 0x19, 0xa0, 0x00, 0xb1, 0x00, 0x85, 0x1b, 0xc8, 0xb1, 0x00,
                                  0x20, 0x3a, 0xf3, 0xe6, 0x18, 0xc6, 0x1b, 0xd0, 0xf4, 0x60, 0x85, 0x1a, 0x98, 0x48, 0xa9, 0x40,
                                  0x05, 0x15, 0x8d, 0x01, 0x50, 0xa5, 0x18, 0x8d, 0x04, 0x50, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0xa5,
                                  0x1a, 0xc9, 0x61, 0xb0, 0x41, 0xc9, 0x41, 0xb0, 0x25, 0xa2, 0x00, 0xc9, 0x20, 0xf0, 0x0e, 0xb0,
                                  0x05, 0xa2, 0x00, 0x4c, 0x6d, 0xf3, 0x38, 0xe9, 0x2f, 0x0a, 0x0a, 0x0a, 0xaa, 0x86, 0x1a, 0xa0,
                                  0x07, 0xbd, 0x29, 0x60, 0x8d, 0x07, 0x50, 0xe8, 0x88, 0x10, 0xf6, 0x4c, 0xab, 0xf3, 0x38, 0xe9,
                                  0x41, 0x0a, 0x0a, 0x0a, 0xaa, 0x86, 0x1a, 0xa0, 0x07, 0xbd, 0x81, 0x60, 0x8d, 0x07, 0x50, 0xe8,
                                  0x88, 0x10, 0xf6, 0x4c, 0xab, 0xf3, 0x38, 0xe9, 0x61, 0x0a, 0x0a, 0x0a, 0xaa, 0x86, 0x1a, 0xa0,
                                  0x07, 0xbd, 0x51, 0x61, 0x8d, 0x07, 0x50, 0xe8, 0x88, 0x10, 0xf6, 0x68, 0xa8, 0x60, 0xa5, 0x00,
                                  0x48, 0xa5, 0x01, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa0, 0x00, 0xb1, 0x00, 0xc9,
                                  0xfe, 0xd0, 0x03, 0x4c, 0xf2, 0xf3, 0x85, 0x19, 0xa9, 0x00, 0x85, 0x18, 0x20, 0x75, 0xf4, 0xb1,
                                  0x00, 0xc9, 0xff, 0xf0, 0x17, 0x85, 0x1a, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0x85, 0x1b, 0xa5, 0x06,
                                  0x85, 0x02, 0xa5, 0x07, 0x85, 0x03, 0x20, 0x30, 0xf4, 0x4c, 0xcc, 0xf3, 0x20, 0x75, 0xf4, 0x4c,
                                  0xbd, 0xf3, 0x68, 0x85, 0x01, 0x68, 0x85, 0x00, 0xa0, 0x00, 0xb1, 0x00, 0xc9, 0xfe, 0xd0, 0x03,
                                  0x4c, 0x2f, 0xf4, 0x85, 0x19, 0xa9, 0x80, 0x85, 0x18, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0xc9, 0xff,
                                  0xf0, 0x17, 0x85, 0x1a, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0x85, 0x1b, 0xa5, 0x08, 0x85, 0x02, 0xa5,
                                  0x09, 0x85, 0x03, 0x20, 0x30, 0xf4, 0x4c, 0x09, 0xf4, 0x20, 0x75, 0xf4, 0x4c, 0xfa, 0xf3, 0x60,
                                  0x48, 0x98, 0x48, 0xa5, 0x1a, 0xd0, 0x0a, 0xa5, 0x18, 0x18, 0x65, 0x1b, 0x85, 0x18, 0x4c, 0x71,
                                  0xf4, 0xc9, 0x20, 0x90, 0x07, 0xe6, 0x03, 0x38, 0xe9, 0x20, 0xb0, 0xf5, 0x0a, 0x0a, 0x0a, 0x85,
                                  0x1a, 0xa5, 0x18, 0x8d, 0x04, 0x50, 0xa5, 0x19, 0x0a, 0x0a, 0x0a, 0x8d, 0x05, 0x50, 0xa4, 0x1a,
                                  0xa2, 0x07, 0xb1, 0x02, 0x8d, 0x07, 0x50, 0xc8, 0xca, 0x10, 0xf7, 0xe6, 0x18, 0xc6, 0x1b, 0xd0,
                                  0xe0, 0x68, 0xa8, 0x68, 0x60, 0xc8, 0xd0, 0x02, 0xe6, 0x01, 0x60, 0xa5, 0x00, 0x48, 0xa5, 0x01,
                                  0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa0, 0x00, 0xb1, 0x00, 0xc9, 0xfe, 0xd0, 0x03,
                                  0x4c, 0xbc, 0xf4, 0x85, 0x19, 0xa9, 0x00, 0x85, 0x18, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0xc9, 0xff,
                                  0xf0, 0x14, 0x85, 0x1a, 0xa9, 0x01, 0x85, 0x1b, 0xa5, 0x06, 0x85, 0x02, 0xa5, 0x07, 0x85, 0x03,
                                  0x20, 0x30, 0xf4, 0x4c, 0x99, 0xf4, 0x20, 0x75, 0xf4, 0x4c, 0x8a, 0xf4, 0x68, 0x85, 0x01, 0x68,
                                  0x85, 0x00, 0xa0, 0x00, 0xb1, 0x00, 0xc9, 0xfe, 0xd0, 0x03, 0x4c, 0xf6, 0xf4, 0x85, 0x19, 0xa9,
                                  0x80, 0x85, 0x18, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0xc9, 0xff, 0xf0, 0x14, 0x85, 0x1a, 0xa9, 0x01,
                                  0x85, 0x1b, 0xa5, 0x08, 0x85, 0x02, 0xa5, 0x09, 0x85, 0x03, 0x20, 0x30, 0xf4, 0x4c, 0xd3, 0xf4,
                                  0x20, 0x75, 0xf4, 0x4c, 0xc4, 0xf4, 0x60, 0xa9, 0x00, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa0, 0xe6,
                                  0x8c, 0x05, 0x50, 0xa9, 0x00, 0xa2, 0x20, 0x8d, 0x04, 0x50, 0x8d, 0x07, 0x50, 0xca, 0xd0, 0xfa,
                                  0xc8, 0xc0, 0xff, 0xd0, 0xeb, 0xa0, 0x00, 0xb1, 0x00, 0xc9, 0xfe, 0xf0, 0x2c, 0x18, 0x69, 0xe6,
                                  0x8d, 0x05, 0x50, 0xa9, 0x00, 0x8d, 0x04, 0x50, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0xc9, 0xff, 0xf0,
                                  0x13, 0x85, 0x1a, 0x20, 0x75, 0xf4, 0xb1, 0x00, 0xaa, 0xa5, 0x1a, 0x8d, 0x07, 0x50, 0xca, 0xd0,
                                  0xfa, 0x4c, 0x28, 0xf5, 0x20, 0x75, 0xf4, 0xd0, 0xce, 0x60, 0xa9, 0x00, 0x05, 0x15, 0x8d, 0x01,
                                  0x50, 0xa0, 0xe6, 0x8c, 0x05, 0x50, 0xa9, 0x00, 0xa2, 0x20, 0x8d, 0x04, 0x50, 0x8d, 0x07, 0x50,
                                  0xca, 0xd0, 0xfa, 0xc8, 0xc0, 0xff, 0xd0, 0xeb, 0xa0, 0x00, 0xb1, 0x00, 0xc9, 0xfe, 0xf0, 0x1f,
                                  0x18, 0x69, 0xe6, 0x8d, 0x05, 0x50, 0xa9, 0x00, 0x8d, 0x04, 0x50, 0x20, 0x75, 0xf4, 0xb1, 0x00,
                                  0xc9, 0xff, 0xf0, 0x06, 0x8d, 0x07, 0x50, 0x4c, 0x7b, 0xf5, 0x20, 0x75, 0xf4, 0xd0, 0xdb, 0x60,
                                  0xa9, 0x80, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa9, 0x00, 0x85, 0x1e, 0x20, 0xad, 0xf5, 0xa9, 0x80,
                                  0x85, 0x1e, 0x20, 0xad, 0xf5, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0x60, 0xa0, 0x00, 0xa5,
                                  0x1e, 0x8d, 0x04, 0x50, 0x8c, 0x05, 0x50, 0xa2, 0x20, 0xa9, 0x00, 0x8d, 0x07, 0x50, 0xca, 0xd0,
                                  0xfa, 0xc8, 0xc0, 0xc8, 0xd0, 0xe9, 0x60, 0x86, 0x18, 0x84, 0x19, 0x46, 0x18, 0x46, 0x18, 0x46,
                                  0x18, 0xa5, 0x18, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0x46, 0x1c, 0x46, 0x1c, 0x46,
                                  0x1c, 0x20, 0xf5, 0xf5, 0xa5, 0x02, 0x85, 0x00, 0xa5, 0x03, 0x85, 0x01, 0x68, 0x09, 0x80, 0x85,
                                  0x18, 0x20, 0xf5, 0xf5, 0x60, 0xa5, 0x1c, 0x85, 0x1e, 0xa0, 0x00, 0xa5, 0x18, 0x8d, 0x04, 0x50,
                                  0xa5, 0x19, 0x8d, 0x05, 0x50, 0xa5, 0x1d, 0x85, 0x1f, 0xb1, 0x00, 0x8d, 0x07, 0x50, 0xc8, 0xc6,
                                  0x1f, 0xd0, 0xf6, 0xe6, 0x18, 0xc6, 0x1e, 0xd0, 0xe2, 0x60, 0xa2, 0x10, 0xa0, 0x00, 0xa9, 0xff,
                                  0x99, 0x23, 0x00, 0x99, 0x28, 0x00, 0x98, 0x18, 0x69, 0x08, 0xa8, 0xca, 0xd0, 0xf0, 0x60, 0x48,
                                  0x98, 0x48, 0x8a, 0x48, 0xa2, 0x08, 0xa0, 0x00, 0xb9, 0x28, 0x00, 0xc9, 0xff, 0xf0, 0x19, 0xb9,
                                  0x26, 0x00, 0x4a, 0x4a, 0x4a, 0x85, 0x18, 0x85, 0x1e, 0xb9, 0x27, 0x00, 0x29, 0xf8, 0x85, 0x19,
                                  0x4a, 0x4a, 0x4a, 0x85, 0x1f, 0x20, 0xc4, 0xf6, 0x98, 0x18, 0x69, 0x08, 0xa8, 0xca, 0xd0, 0xd8,
                                  0xa2, 0x08, 0xa0, 0x00, 0xb9, 0x68, 0x00, 0xc9, 0xff, 0xf0, 0x19, 0xb9, 0x66, 0x00, 0x4a, 0x4a,
                                  0x4a, 0x85, 0x18, 0x85, 0x1e, 0xb9, 0x67, 0x00, 0x29, 0xf8, 0x85, 0x19, 0x4a, 0x4a, 0x4a, 0x85,
                                  0x1f, 0x20, 0x9d, 0xf9, 0x98, 0x18, 0x69, 0x08, 0xa8, 0xca, 0xd0, 0xd8, 0xa2, 0x08, 0xa0, 0x00,
                                  0x8a, 0x48, 0xa2, 0x00, 0xb9, 0x21, 0x00, 0x9d, 0x00, 0x03, 0xc8, 0xe8, 0xe0, 0x08, 0xd0, 0xf4,
                                  0x68, 0xaa, 0xad, 0x02, 0x03, 0xc9, 0xff, 0xf0, 0x0f, 0x20, 0x88, 0xf7, 0x20, 0xed, 0xf7, 0x20,
                                  0xa1, 0xf8, 0x20, 0xce, 0xf8, 0x20, 0xfa, 0xf8, 0xca, 0xd0, 0xd5, 0x20, 0x63, 0xf9, 0x68, 0xaa,
                                  0x68, 0xa8, 0x68, 0x60, 0x98, 0x48, 0x8a, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa5,
                                  0x1f, 0x18, 0x69, 0xe6, 0x85, 0x1f, 0xa0, 0x00, 0xa9, 0x03, 0x85, 0x1b, 0xa6, 0x1e, 0xa5, 0x1f,
                                  0x85, 0x1d, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xad, 0x06, 0x50, 0x99, 0x08, 0x03, 0xe6, 0x1d,
                                  0xa5, 0x1d, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xad, 0x06, 0x50, 0x99, 0x09, 0x03, 0xe6, 0x1d,
                                  0xa5, 0x1d, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xad, 0x06, 0x50, 0x99, 0x0a, 0x03, 0xc8, 0xc8,
                                  0xc8, 0xe8, 0xc6, 0x1b, 0xd0, 0xc8, 0xa0, 0x00, 0xa9, 0x03, 0x85, 0x1c, 0xa6, 0x18, 0xa9, 0x03,
                                  0x85, 0x1d, 0x8e, 0x04, 0x50, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0xb9, 0x08, 0x03, 0x20, 0x4b, 0xf7,
                                  0xc8, 0xc6, 0x1d, 0xd0, 0xf5, 0xe8, 0xc6, 0x1c, 0xd0, 0xe4, 0xa5, 0x18, 0xc9, 0x80, 0xb0, 0x06,
                                  0x09, 0x80, 0x85, 0x18, 0xd0, 0xd0, 0x68, 0xaa, 0x68, 0xa8, 0x60, 0x85, 0x1a, 0x8a, 0x48, 0x98,
                                  0x48, 0xa5, 0x06, 0x85, 0x02, 0xa5, 0x07, 0x85, 0x03, 0xa6, 0x18, 0xe0, 0x80, 0x90, 0x08, 0xa5,
                                  0x08, 0x85, 0x02, 0xa5, 0x09, 0x85, 0x03, 0xa5, 0x1a, 0xc9, 0x20, 0x90, 0x07, 0xe6, 0x03, 0x38,
                                  0xe9, 0x20, 0xb0, 0xf5, 0x0a, 0x0a, 0x0a, 0xa8, 0xa2, 0x08, 0xb1, 0x02, 0x8d, 0x07, 0x50, 0xc8,
                                  0xca, 0xd0, 0xf7, 0x68, 0xa8, 0x68, 0xaa, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa9, 0x40, 0x05,
                                  0x15, 0x8d, 0x01, 0x50, 0xad, 0x00, 0x03, 0x4a, 0x4a, 0x4a, 0x85, 0x18, 0xad, 0x01, 0x03, 0x85,
                                  0x19, 0xa9, 0x08, 0x85, 0x00, 0xa9, 0x03, 0x85, 0x01, 0xa6, 0x18, 0xa0, 0x00, 0xa5, 0x19, 0x85,
                                  0x1b, 0xa5, 0x1b, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xad, 0x06, 0x50, 0x91, 0x00, 0xe6, 0x1b,
                                  0xc8, 0xc0, 0x30, 0xf0, 0x0c, 0xc0, 0x20, 0xf0, 0x04, 0xc0, 0x10, 0xd0, 0xe4, 0xe8, 0x4c, 0xad,
                                  0xf7, 0xa5, 0x18, 0xaa, 0xc9, 0x80, 0xb0, 0x0f, 0xa9, 0x38, 0x85, 0x00, 0xa9, 0x03, 0x85, 0x01,
                                  0x8a, 0x09, 0x80, 0x85, 0x18, 0xd0, 0xc2, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48,
                                  0x98, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa9, 0x68, 0x85, 0x00, 0xa9, 0x03, 0x85,
                                  0x01, 0xa9, 0x00, 0x85, 0x1b, 0xad, 0x02, 0x03, 0xa8, 0x20, 0x4e, 0xf8, 0x20, 0x95, 0xf8, 0x98,
                                  0x18, 0x69, 0x02, 0x20, 0x4e, 0xf8, 0x20, 0x95, 0xf8, 0x98, 0x18, 0x69, 0x01, 0x20, 0x4e, 0xf8,
                                  0x20, 0x95, 0xf8, 0x98, 0x18, 0x69, 0x03, 0x20, 0x4e, 0xf8, 0xa5, 0x1b, 0xd0, 0x0d, 0xe6, 0x1b,
                                  0xa9, 0x98, 0x85, 0x00, 0xa9, 0x03, 0x85, 0x01, 0x4c, 0x05, 0xf8, 0xa0, 0x0f, 0xa9, 0x00, 0x99,
                                  0x88, 0x03, 0x99, 0xb8, 0x03, 0x88, 0x10, 0xf7, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x85, 0x1a,
                                  0x8a, 0x48, 0x98, 0x48, 0xa5, 0x06, 0x85, 0x02, 0xa5, 0x07, 0x85, 0x03, 0xa5, 0x1b, 0xf0, 0x08,
                                  0xa5, 0x08, 0x85, 0x02, 0xa5, 0x09, 0x85, 0x03, 0xa5, 0x1a, 0xc9, 0x20, 0x90, 0x07, 0xe6, 0x03,
                                  0x38, 0xe9, 0x20, 0xb0, 0xf5, 0x0a, 0x0a, 0x0a, 0xa8, 0xa5, 0x00, 0x48, 0xa2, 0x08, 0x86, 0x1c,
                                  0xa2, 0x00, 0xb1, 0x02, 0x81, 0x00, 0xc8, 0xe6, 0x00, 0xc6, 0x1c, 0xd0, 0xf5, 0x68, 0x85, 0x00,
                                  0x68, 0xa8, 0x68, 0xaa, 0x60, 0xa5, 0x00, 0x18, 0x69, 0x08, 0x85, 0x00, 0x90, 0x02, 0xe6, 0x01,
                                  0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xad, 0x00, 0x03, 0x29, 0x07, 0xf0, 0x1b, 0xa8, 0xa2, 0x0f,
                                  0x5e, 0x68, 0x03, 0x7e, 0x78, 0x03, 0x7e, 0x88, 0x03, 0x5e, 0x98, 0x03, 0x7e, 0xa8, 0x03, 0x7e,
                                  0xb8, 0x03, 0xca, 0x10, 0xeb, 0x88, 0xd0, 0xe6, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a,
                                  0x48, 0x98, 0x48, 0xa2, 0x2f, 0xbd, 0x68, 0x03, 0x1d, 0x98, 0x03, 0x49, 0xff, 0xa8, 0x3d, 0x08,
                                  0x03, 0x1d, 0x68, 0x03, 0x9d, 0x68, 0x03, 0x98, 0x3d, 0x38, 0x03, 0x1d, 0x98, 0x03, 0x9d, 0x98,
                                  0x03, 0xca, 0x10, 0xe1, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa9,
                                  0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xad, 0x00, 0x03, 0x4a, 0x4a, 0x4a, 0x85, 0x18, 0xaa, 0xad,
                                  0x01, 0x03, 0x85, 0x19, 0xa0, 0x00, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xb9, 0x68,
                                  0x03, 0x8d, 0x07, 0x50, 0xc8, 0xc0, 0x30, 0xf0, 0x0c, 0xc0, 0x20, 0xf0, 0x04, 0xc0, 0x10, 0xd0,
                                  0xed, 0xe8, 0x4c, 0x16, 0xf9, 0xa5, 0x18, 0x09, 0x80, 0x85, 0x18, 0xaa, 0xa0, 0x00, 0xa5, 0x19,
                                  0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xb9, 0x98, 0x03, 0x8d, 0x07, 0x50, 0xc8, 0xc0, 0x30, 0xf0,
                                  0x0c, 0xc0, 0x20, 0xf0, 0x04, 0xc0, 0x10, 0xd0, 0xed, 0xe8, 0x4c, 0x3e, 0xf9, 0x68, 0xa8, 0x68,
                                  0xaa, 0x68, 0x60, 0x48, 0x98, 0x48, 0x8a, 0x48, 0xa2, 0x08, 0xa0, 0x00, 0x8a, 0x48, 0xa2, 0x00,
                                  0xb9, 0x61, 0x00, 0x9d, 0x00, 0x03, 0xc8, 0xe8, 0xe0, 0x08, 0xd0, 0xf4, 0x68, 0xaa, 0xad, 0x02,
                                  0x03, 0xc9, 0xff, 0xf0, 0x0f, 0x20, 0x13, 0xfa, 0x20, 0x74, 0xfa, 0x20, 0xb3, 0xfa, 0x20, 0xda,
                                  0xfa, 0x20, 0x06, 0xfb, 0xca, 0xd0, 0xd5, 0x68, 0xaa, 0x68, 0xa8, 0x68, 0x60, 0x98, 0x48, 0x8a,
                                  0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xa5, 0x1f, 0x18, 0x69, 0xe6, 0x85, 0x1f, 0xa0,
                                  0x00, 0xa9, 0x02, 0x85, 0x1b, 0xa6, 0x1e, 0xa5, 0x1f, 0x85, 0x1d, 0x8d, 0x05, 0x50, 0x8e, 0x04,
                                  0x50, 0xad, 0x06, 0x50, 0x99, 0x08, 0x03, 0xe6, 0x1d, 0xa5, 0x1d, 0x8d, 0x05, 0x50, 0x8e, 0x04,
                                  0x50, 0xad, 0x06, 0x50, 0x99, 0x09, 0x03, 0xc8, 0xc8, 0xe8, 0xc6, 0x1b, 0xd0, 0xd9, 0xa0, 0x00,
                                  0xa9, 0x02, 0x85, 0x1c, 0xa6, 0x18, 0xa9, 0x02, 0x85, 0x1d, 0x8e, 0x04, 0x50, 0xa5, 0x19, 0x8d,
                                  0x05, 0x50, 0xb9, 0x08, 0x03, 0x20, 0x4b, 0xf7, 0xc8, 0xc6, 0x1d, 0xd0, 0xf5, 0xe8, 0xc6, 0x1c,
                                  0xd0, 0xe4, 0xa5, 0x18, 0xc9, 0x80, 0xb0, 0x06, 0x09, 0x80, 0x85, 0x18, 0xd0, 0xd0, 0x68, 0xaa,
                                  0x68, 0xa8, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d, 0x01, 0x50, 0xad,
                                  0x00, 0x03, 0x4a, 0x4a, 0x4a, 0x85, 0x18, 0xad, 0x01, 0x03, 0x85, 0x19, 0xa9, 0x08, 0x85, 0x00,
                                  0xa9, 0x03, 0x85, 0x01, 0xa6, 0x18, 0xa0, 0x00, 0xa5, 0x19, 0x85, 0x1b, 0xa5, 0x1b, 0x8d, 0x05,
                                  0x50, 0x8e, 0x04, 0x50, 0xad, 0x06, 0x50, 0x91, 0x00, 0xe6, 0x1b, 0xc8, 0xc0, 0x10, 0xf0, 0x08,
                                  0xc0, 0x08, 0xd0, 0xe8, 0xe8, 0x4c, 0x38, 0xfa, 0xa5, 0x18, 0xaa, 0xc9, 0x80, 0xb0, 0x0f, 0xa9,
                                  0x38, 0x85, 0x00, 0xa9, 0x03, 0x85, 0x01, 0x8a, 0x09, 0x80, 0x85, 0x18, 0xd0, 0xc6, 0x68, 0xa8,
                                  0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa9, 0x68, 0x85, 0x00, 0xa9, 0x03, 0x85,
                                  0x01, 0xa9, 0x00, 0x85, 0x1b, 0xad, 0x02, 0x03, 0xa8, 0x20, 0x4e, 0xf8, 0x20, 0x95, 0xf8, 0xa5,
                                  0x1b, 0xd0, 0x0d, 0xe6, 0x1b, 0xa9, 0x98, 0x85, 0x00, 0xa9, 0x03, 0x85, 0x01, 0x4c, 0x85, 0xfa,
                                  0xa0, 0x07, 0xa9, 0x00, 0x99, 0x70, 0x03, 0x99, 0xa0, 0x03, 0x88, 0x10, 0xf7, 0x68, 0xa8, 0x68,
                                  0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xad, 0x00, 0x03, 0x29, 0x07, 0xf0, 0x15, 0xa8,
                                  0xa2, 0x07, 0x5e, 0x68, 0x03, 0x7e, 0x70, 0x03, 0x5e, 0x98, 0x03, 0x7e, 0xa0, 0x03, 0xca, 0x10,
                                  0xf1, 0x88, 0xd0, 0xec, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa2,
                                  0x0f, 0xbd, 0x68, 0x03, 0x1d, 0x98, 0x03, 0x49, 0xff, 0xa8, 0x3d, 0x08, 0x03, 0x1d, 0x68, 0x03,
                                  0x9d, 0x68, 0x03, 0x98, 0x3d, 0x38, 0x03, 0x1d, 0x98, 0x03, 0x9d, 0x98, 0x03, 0xca, 0x10, 0xe1,
                                  0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0x48, 0x8a, 0x48, 0x98, 0x48, 0xa9, 0x40, 0x05, 0x15, 0x8d,
                                  0x01, 0x50, 0xad, 0x00, 0x03, 0x4a, 0x4a, 0x4a, 0x85, 0x18, 0xaa, 0xad, 0x01, 0x03, 0x85, 0x19,
                                  0xa0, 0x00, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xb9, 0x68, 0x03, 0x8d, 0x07, 0x50,
                                  0xc8, 0xc0, 0x10, 0xf0, 0x08, 0xc0, 0x08, 0xd0, 0xf1, 0xe8, 0x4c, 0x22, 0xfb, 0xa5, 0x18, 0x09,
                                  0x80, 0x85, 0x18, 0xaa, 0xa0, 0x00, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0x8e, 0x04, 0x50, 0xb9, 0x98,
                                  0x03, 0x8d, 0x07, 0x50, 0xc8, 0xc0, 0x10, 0xf0, 0x08, 0xc0, 0x08, 0xd0, 0xf1, 0xe8, 0x4c, 0x46,
                                  0xfb, 0x68, 0xa8, 0x68, 0xaa, 0x68, 0x60, 0xa9, 0x19, 0x85, 0x1d, 0xa9, 0xff, 0x85, 0x1c, 0xa2,
                                  0x00, 0xa0, 0xe6, 0xa9, 0x00, 0x20, 0x00, 0xff, 0x60, 0x98, 0x48, 0x8a, 0x48, 0xa5, 0x12, 0x05,
                                  0x13, 0xd0, 0x06, 0xa9, 0xff, 0x85, 0x12, 0x85, 0x13, 0xa5, 0x13, 0x29, 0x04, 0x0a, 0x0a, 0x0a,
                                  0x0a, 0x0a, 0x85, 0x14, 0xa5, 0x12, 0x29, 0x10, 0x0a, 0x0a, 0x0a, 0x45, 0x14, 0x0a, 0x26, 0x12,
                                  0x26, 0x13, 0x68, 0xaa, 0x68, 0xa8, 0xa5, 0x12, 0x60, 0x20, 0x90, 0xf5, 0xa9, 0x00, 0x8d, 0x02,
                                  0x50, 0x8d, 0x03, 0x50, 0x8d, 0xe0, 0x00, 0x8d, 0xe1, 0x00, 0x8d, 0xe2, 0x00, 0x8d, 0xe5, 0x00,
                                  0x8d, 0xe6, 0x00, 0xa9, 0x70, 0x8d, 0xe3, 0x00, 0xa9, 0x80, 0x8d, 0xe7, 0x00, 0x20, 0xeb, 0xfb,
                                  0xad, 0xe1, 0x00, 0xae, 0xe0, 0x00, 0xa0, 0x00, 0x20, 0x42, 0xff, 0xa9, 0xa1, 0x85, 0x00, 0xa9,
                                  0x00, 0x85, 0x01, 0xa2, 0x10, 0xa0, 0x10, 0x20, 0x1d, 0xf3, 0x60, 0xa0, 0x00, 0xb1, 0xe2, 0x18,
                                  0x6d, 0xe0, 0x00, 0x8d, 0xe0, 0x00, 0xad, 0xe1, 0x00, 0x69, 0x00, 0x8d, 0xe1, 0x00, 0xc8, 0xd0,
                                  0xec, 0xee, 0xe3, 0x00, 0xad, 0xe3, 0x00, 0xcd, 0xe7, 0x00, 0xd0, 0xe1, 0x60, 0x78, 0xa9, 0x00,
                                  0x85, 0x0c, 0xa2, 0xff, 0x9a, 0x58, 0xd8, 0xa9, 0x00, 0x85, 0x0b, 0xa9, 0xff, 0x85, 0x12, 0x85,
                                  0x13, 0x20, 0x79, 0xfb, 0xa5, 0x0b, 0xf0, 0xf9, 0x4c, 0x2e, 0xfc, 0x4c, 0x39, 0xf0, 0xa9, 0x20,
                                  0x8d, 0x00, 0x59, 0xad, 0x00, 0x5a, 0x29, 0x01, 0xf0, 0x34, 0xad, 0x00, 0x5a, 0x29, 0x02, 0xf0,
                                  0x0f, 0x20, 0xc4, 0xfd, 0x58, 0xa2, 0xff, 0x9a, 0xa9, 0x00, 0x8d, 0x00, 0x59, 0x4c, 0x39, 0xf0,
                                  0xad, 0x02, 0x60, 0xc9, 0x01, 0xf0, 0xea, 0xa2, 0x00, 0xbd, 0x68, 0xfc, 0x9d, 0x00, 0x02, 0xe8,
                                  0xe0, 0x10, 0xd0, 0xf5, 0x78, 0x4c, 0x00, 0x02, 0xad, 0x00, 0x58, 0x6c, 0xfc, 0xff, 0xa9, 0x55,
                                  0x8d, 0x00, 0x44, 0xa5, 0x0b, 0x69, 0x3c, 0xc5, 0x0b, 0xd0, 0xfc, 0xa9, 0xaa, 0x8d, 0x00, 0x44,
                                  0x78, 0x4c, 0x00, 0xfd, 0x20, 0x63, 0xfd, 0x20, 0x9b, 0xfd, 0x58, 0xa5, 0x0b, 0x69, 0x32, 0xc5,
                                  0x0b, 0xd0, 0xfc, 0xa9, 0x00, 0x8d, 0x00, 0x59, 0xa9, 0x00, 0x8d, 0x00, 0x44, 0x4c, 0x98, 0xfc,
                                  0x5e, 0x08, 0x81, 0xe3, 0xf0, 0xff, 0x89, 0x46, 0x06, 0x33, 0xc0, 0x0b, 0xd8, 0x74, 0x08, 0xb8,
                                  0xff, 0xff, 0x83, 0xc4, 0x0a, 0x5d, 0xcb, 0xb9, 0x04, 0x00, 0x8b, 0x46, 0x08, 0x8b, 0x5e, 0x06,
                                  0xd1, 0xf8, 0xd1, 0xdb, 0xe2, 0xfa, 0x53, 0x89, 0x5e, 0x04, 0x9a, 0x9e, 0x04, 0xb1, 0x29, 0x8b,
                                  0xe5, 0x85, 0xc0, 0x74, 0x08, 0xb8, 0xff, 0xff, 0x83, 0xc4, 0x0a, 0x5d, 0xcb, 0x8b, 0x46, 0x08,
                                  0x8b, 0x5e, 0x06, 0x81, 0xe3, 0xf0, 0xff, 0xa3, 0x26, 0x00, 0x89, 0x1e, 0x24, 0x00, 0x33, 0xc0,
                                  0x33, 0xdb, 0xa3, 0x98, 0x14, 0x89, 0x1e, 0x96, 0x14, 0xa3, 0x90, 0x14, 0x89, 0x1e, 0x8e, 0x14,
                                  0xa2, 0x00, 0xa9, 0x55, 0x8d, 0x00, 0x02, 0x95, 0x00, 0xe8, 0xd0, 0xfb, 0xb5, 0x00, 0xcd, 0x00,
                                  0x02, 0xd0, 0x48, 0x49, 0xff, 0x95, 0x00, 0xe8, 0xd0, 0xf2, 0xad, 0x00, 0x02, 0x49, 0xff, 0x8d,
                                  0x00, 0x02, 0xc9, 0x55, 0xd0, 0xe6, 0xa9, 0x00, 0x85, 0xe2, 0xa9, 0x01, 0x85, 0xe3, 0xa0, 0x00,
                                  0xa9, 0x55, 0x85, 0xe4, 0x91, 0xe2, 0xc8, 0xd0, 0xfb, 0xb1, 0xe2, 0xc5, 0xe4, 0xd0, 0x1c, 0x49,
                                  0xff, 0x91, 0xe2, 0xc8, 0xd0, 0xf3, 0xa5, 0xe4, 0x49, 0xff, 0x85, 0xe4, 0xc9, 0x55, 0xd0, 0xe9,
                                  0xe6, 0xe3, 0xa5, 0xe3, 0xc9, 0x04, 0xd0, 0xd8, 0x4c, 0x84, 0xfc, 0xa9, 0xff, 0x8d, 0x00, 0x44,
                                  0x4c, 0x5b, 0xfd, 0xa9, 0x55, 0x85, 0xe4, 0xa9, 0x00, 0x85, 0xe8, 0x85, 0x0a, 0xa5, 0xe4, 0x8d,
                                  0x00, 0x44, 0xad, 0x00, 0x4c, 0xad, 0x00, 0x4c, 0xad, 0x00, 0x4c, 0xad, 0x00, 0x4c, 0xad, 0x00,
                                  0x4c, 0xad, 0x00, 0x4c, 0xad, 0x00, 0x4c, 0xad, 0x00, 0x4c, 0xa5, 0xe8, 0xf0, 0xfc, 0xa5, 0x0a,
                                  0xc5, 0xe4, 0xd0, 0xc7, 0x49, 0xff, 0xc9, 0x55, 0xd0, 0xcb, 0x60, 0xa9, 0x00, 0x85, 0xe0, 0x85,
                                  0xe1, 0x85, 0xe7, 0x85, 0xe2, 0xa9, 0x34, 0x85, 0xe5, 0xa9, 0xcb, 0x85, 0xe6, 0xa9, 0xf0, 0x85,
                                  0xe3, 0x20, 0x48, 0xfe, 0x60, 0x42, 0x49, 0x54, 0x20, 0x43, 0x4f, 0x52, 0x50, 0x4f, 0x52, 0x41,
                                  0x54, 0x49, 0x4f, 0x4e, 0x78, 0xd8, 0xa2, 0x00, 0xbd, 0xb5, 0xfd, 0x85, 0x04, 0xa0, 0x09, 0x06,
                                  0x04, 0x2a, 0x2a, 0x2a, 0x8d, 0x00, 0x60, 0x88, 0xd0, 0xf5, 0xe8, 0xe0, 0x0f, 0xd0, 0xe9, 0xa2,
                                  0x00, 0xad, 0x00, 0x60, 0x4a, 0x4a, 0x26, 0x04, 0xe8, 0xe0, 0x08, 0xd0, 0xf4, 0xa5, 0x04, 0xc9,
                                  0x47, 0xd0, 0x07, 0x20, 0x01, 0xfe, 0x20, 0x2a, 0xfe, 0x60, 0xb9, 0x00, 0x60, 0xc8, 0x4c, 0xfa,
                                  0xfd, 0xa2, 0x00, 0xbd, 0x05, 0x60, 0xdd, 0x11, 0xfe, 0xd0, 0xef, 0xe8, 0xe0, 0x19, 0xd0, 0xf3,
                                  0x60, 0x43, 0x4f, 0x50, 0x59, 0x52, 0x49, 0x47, 0x48, 0x54, 0x20, 0x42, 0x49, 0x54, 0x20, 0x43,
                                  0x4f, 0x52, 0x50, 0x4f, 0x52, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0xa9, 0x70, 0x85, 0xe3, 0xa9, 0x00,
                                  0x85, 0xe2, 0x85, 0xe0, 0x85, 0xe1, 0xad, 0x00, 0x60, 0x85, 0xe5, 0xad, 0x01, 0x60, 0x85, 0xe6,
                                  0xa9, 0x80, 0x85, 0xe7, 0x20, 0x48, 0xfe, 0x60, 0xa0, 0x00, 0xb1, 0xe2, 0x18, 0x65, 0xe0, 0x85,
                                  0xe0, 0xa5, 0xe1, 0x69, 0x00, 0x85, 0xe1, 0xc8, 0xd0, 0xf0, 0xe6, 0xe3, 0xa5, 0xe3, 0xc5, 0xe7,
                                  0xd0, 0xe8, 0xa5, 0xe5, 0xc5, 0xe0, 0xd0, 0x07, 0xa5, 0xe6, 0xc5, 0xe1, 0xd0, 0x01, 0x60, 0x4c,
                                  0xfa, 0xfd, 0xb1, 0x29, 0xa3, 0xa0, 0x14, 0x89, 0x1e, 0x9e, 0x14, 0x33, 0xc0, 0x83, 0xc4, 0x02,
                                  0x5d, 0xcb, 0xb8, 0xf2, 0xff, 0x9a, 0x4a, 0x05, 0xb1, 0x29, 0x33, 0xc9, 0xba, 0x02, 0x00, 0x8b,
                                  0x46, 0x16, 0x8b, 0x5e, 0x14, 0x9a, 0xd0, 0x06, 0xb1, 0x29, 0x8e, 0xc0, 0x26, 0x8b, 0x0f, 0x49,
                                  0x49, 0x89, 0x4e, 0x0c, 0x8b, 0x0e, 0xa0, 0x14, 0x8b, 0x16, 0x9e, 0x14, 0x9a, 0xca, 0x05, 0xb1,
                                  0x29, 0x89, 0x46, 0x06, 0x89, 0x5e, 0x04, 0x74, 0x09, 0x33, 0xc0, 0x50, 0x0e, 0xe8, 0xf3, 0xfe,
                                  0x8b, 0xe5, 0xff, 0x76, 0x18, 0x0e, 0xe8, 0xea, 0xfe, 0x8b, 0xe5, 0x89, 0x46, 0x0a, 0x0b, 0xc3,
                                  0x89, 0x5e, 0x08, 0x74, 0x2f, 0x8b, 0x46, 0x18, 0x8b, 0x5e, 0x0c, 0x3b, 0xd8, 0x76, 0x03, 0x89,
                                  0x46, 0x0c, 0xff, 0x76, 0x0c, 0xff, 0x76, 0x16, 0xff, 0x76, 0x14, 0xff, 0x76, 0x0a, 0xff, 0x76,
                                  0x08, 0x9a, 0x2a, 0x04, 0xb1, 0x29, 0x8b, 0xe5, 0xff, 0x76, 0x16, 0xff, 0x76, 0x14, 0x0e, 0xe8,
                                  0x48, 0xa9, 0x00, 0x85, 0xa8, 0x68, 0x4c, 0x0f, 0xff, 0x48, 0xa9, 0x80, 0x85, 0xa8, 0x68, 0x85,
                                  0x1a, 0x84, 0x19, 0x8a, 0x4a, 0x4a, 0x4a, 0x05, 0xa8, 0x85, 0x18, 0xa9, 0x40, 0x05, 0x15, 0x8d,
                                  0x01, 0x50, 0xa5, 0x1c, 0x4a, 0x4a, 0x4a, 0xaa, 0xa5, 0x19, 0x8d, 0x05, 0x50, 0xa5, 0x18, 0x8d,
                                  0x04, 0x50, 0xa5, 0x1a, 0xa4, 0x1d, 0x8d, 0x07, 0x50, 0x88, 0xd0, 0xfa, 0xe6, 0x18, 0xca, 0xd0,
                                  0xe7, 0x60, 0x48, 0x29, 0x0f, 0x09, 0x30, 0x85, 0xa3, 0x68, 0x4a, 0x4a, 0x4a, 0x4a, 0x29, 0x0f,
                                  0x09, 0x30, 0x85, 0xa2, 0x8a, 0x29, 0x0f, 0x09, 0x30, 0x85, 0xa5, 0x8a, 0x4a, 0x4a, 0x4a, 0x4a,
                                  0x29, 0x0f, 0x09, 0x30, 0x85, 0xa4, 0xc0, 0xff, 0xd0, 0x09, 0xa0, 0x20, 0x84, 0xa6, 0x84, 0xa7,
                                  0x4c, 0x85, 0xff, 0x98, 0x29, 0x0f, 0x09, 0x30, 0x85, 0xa7, 0x98, 0x4a, 0x4a, 0x4a, 0x4a, 0x29,
                                  0x0f, 0x09, 0x30, 0x85, 0xa6, 0xa0, 0x00, 0xb9, 0xa2, 0x00, 0xc9, 0x30, 0xd0, 0x0a, 0xa9, 0x20,
                                  0x99, 0xa2, 0x00, 0xc8, 0xc0, 0x05, 0x90, 0xef, 0xa9, 0x06, 0x85, 0xa1, 0x60, 0x78, 0x08, 0x48,
                                  0x98, 0x48, 0xe6, 0x0b, 0xa0, 0x03, 0x18, 0xb9, 0x0e, 0x00, 0x69, 0x01, 0x99, 0x0e, 0x00, 0x90,
                                  0x03, 0x88, 0x10, 0xf2, 0xa5, 0x0c, 0xf0, 0x03, 0x20, 0x26, 0x60, 0x68, 0xa8, 0x68, 0x28, 0x58,
                                  0x40, 0x08, 0x48, 0xad, 0x00, 0x48, 0x85, 0x0a, 0xa9, 0xff, 0x85, 0xe8, 0xa5, 0x0c, 0xf0, 0x03,
                                  0x20, 0x23, 0x60, 0x68, 0x28, 0x40, 0x11, 0x26, 0x8b, 0x44, 0x0e, 0xa9, 0x80, 0x00, 0x74, 0x15,
                                  0x26, 0xf7, 0x44, 0x0e, 0x40, 0x00, 0x74, 0x0d, 0x06, 0x56, 0xb8, 0xff, 0xff, 0x50, 0x00, 0x00,
                                  0x00, 0x97, 0x3d, 0x8b, 0xe5, 0xc4, 0x76, 0x11, 0x26, 0x84, 0xc1, 0xff, 0x0d, 0xfc, 0x9d, 0xff
};

#endif //GAMATE_BIOS_H
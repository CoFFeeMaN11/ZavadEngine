# Zavad Pack File specification

## File structure

| File header | Entry headers | Data |
| ----------- | ------------- | ---- |


### File Header

| ZAV(char[3]) | 0   | revision(uint8_t) | compression_type(uint8_t) | entry_size(uint32_t) | data_offset(uint32_t) |
|:------------:|:---:|:-----------------:|:-------------------------:|:--------------------:|:---------------------:|


- ZAV- file identyfigator
- 0 - terminator
- revision - number of revision (current 1)
- compression_type
  - 0- no compression
  - 1- deflate
- entry_size- number of entries
- data_offset- where data starts

### Entry Header

| name_size(uint8_t) | name(char[name_size]) | uncompressed_size(uint32_t) | compressed_size(uint32_t) | data_offset(uint32_t) | checksum(uint32_t) |
| ------------------ | --------------------- | --------------------------- | ------------------------- | --------------------- | ------------------ |


- name_size- number of bytes dedicate for entry name
- name- name of entry
- uncompressed_size- size of buffer needed to decompresse entry
- compressed_size- size of actual entry stored in pack
- data_offset- offset of entry data relative to data session starts (File Header->data_offset + data_offset)
- checksum- CheckSum in CRC-32

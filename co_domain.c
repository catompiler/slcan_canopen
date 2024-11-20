#include <co_domain.h>
#include <assert.h>
#include <string.h>



static ODR_t co_domain_read_impl(OD_stream_t *stream, void *buf,
                                OD_size_t count, OD_size_t *countRead)
{
	if(stream == NULL || buf == NULL || countRead == NULL) return ODR_DEV_INCOMPAT;

	co_domain_t* dom = (co_domain_t*)stream->object;
	if(dom == NULL) return ODR_DEV_INCOMPAT;

	if(stream->dataOffset == 0){
		stream->dataLength = dom->size;
	}

	size_t offset = stream->dataOffset;
	//if(offset >= dom->size){ offset -= dom->size; }
	if(offset > dom->size) return ODR_DATA_SHORT;

	size_t avail_count = dom->size - offset;
	//if(count > avail_count) return ODR_DATA_SHORT;
	//size_t cur_count = count;
	size_t cur_count = (count <= avail_count) ? count : avail_count;

	if(cur_count > 0){
		uint8_t* data = (uint8_t*)dom->data;
		memcpy(buf, &data[offset], cur_count);
	}

	*countRead = cur_count;

	if((offset + cur_count) >= dom->size){
		stream->dataOffset = 0;
		return ODR_OK;
	}

	stream->dataOffset += cur_count;

	return ODR_PARTIAL;
}

static ODR_t co_domain_write_impl(OD_stream_t *stream, const void *buf,
                                 OD_size_t count, OD_size_t *countWritten)
{
	if(stream == NULL || buf == NULL || countWritten == NULL) return ODR_DEV_INCOMPAT;

	co_domain_t* dom = (co_domain_t*)stream->object;
	if(dom == NULL) return ODR_DEV_INCOMPAT;

	size_t offset = stream->dataOffset;
	//if(offset >= dom->size){ offset -= dom->size; }
	if(offset > dom->size) return ODR_DATA_SHORT;

	size_t avail_count = dom->size - offset;
	//if(count > avail_count) return ODR_DATA_SHORT;
	//size_t cur_count = count;
	size_t cur_count = (count <= avail_count) ? count : avail_count;

	if(cur_count > 0){
		uint8_t* data = (uint8_t*)dom->data;
		memcpy(&data[offset], buf, cur_count);
	}

	*countWritten = cur_count;
	stream->dataOffset += cur_count;

	if(stream->dataLength > 0 && stream->dataOffset >= stream->dataLength){
		stream->dataOffset = 0;
		return ODR_OK;
	}

	return ODR_PARTIAL;
}


CO_ReturnError_t co_domain_init(co_domain_t* dom, void* data, size_t size, OD_entry_t *domainEntry, uint32_t *errInfo)
{
	assert(dom != NULL);

	if(data == NULL || size == 0) return CO_ERROR_ILLEGAL_ARGUMENT;
	if(domainEntry == NULL) return CO_ERROR_ILLEGAL_ARGUMENT;

	dom->data = data;
	dom->size = size;
	dom->extension.object = dom;
	dom->extension.read = co_domain_read_impl;
	dom->extension.write = co_domain_write_impl;
#if OD_FLAGS_PDO_SIZE > 0
	for(int i = 0; i < OD_FLAGS_PDO_SIZE; i ++){
		dom->extension.flagsPDO[i] = 0;
	}
#endif
	ODR_t ret = OD_extension_init(domainEntry, &dom->extension);
	if(ret != ODR_OK){
		if(errInfo) *errInfo = OD_getIndex(domainEntry);
		return CO_ERROR_OD_PARAMETERS;
	}

    return CO_ERROR_NO;
}

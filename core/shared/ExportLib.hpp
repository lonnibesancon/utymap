#if _MSC_VER
	#ifdef UTYMAP_EXPORTS
	#define UTYMAP_API __declspec(dllexport)
	#elif UTYMAP_USING_DLL
	#define UTYMAP_API __declspec(dllimport)
	#else
	#define UTYMAP_API
	#endif
#elif _GCC
#define UTYMAP_API __attribute__((visibility("default")))
#else
#define UTYMAP_API
#endif

#include "Application.hpp"

extern "C"
{
	/// Composes object graph.
	void UTYMAP_API configure(const char* dataPath,    // path to data directory which stores index/ele data
		OnError* errorCallback);

	/// Performs cleanup.
	void UTYMAP_API cleanup();

	/// Register stylesheet.
	void UTYMAP_API registerStylesheet(const char* path);

	/// Registers new in-memory store.
	void UTYMAP_API registerInMemoryStore(const char* key);

	/// Registers new persistent store.
	void UTYMAP_API registerPersistentStore(const char* key, const char* dataPath);

	/// Adds data to store to specific level of details range.
	void UTYMAP_API addToStoreInRange(const char* key,           // store key
		const char* styleFile,     // style file
		const char* path,          // path to data
		int startLod,              // start zoom level
		int endLod,                // end zoom level
		OnError* errorCallback);    // completion callback

	/// Adds data to store to specific level of details range.
	void UTYMAP_API addToStoreInBoundingBox(const char* key,           // store key
		const char* styleFile,     // style file
		const char* path,          // path to data
		double minLat,             // minimal latitude
		double minLon,             // minimal longitude
		double maxLat,             // maximal latitude
		double maxLon,             // maximal longitude
		int startLod,              // start zoom level
		int endLod,                // end zoom level
		OnError* errorCallback);    // completion callback

	/// Adds data to store to specific quadkey only.
	void UTYMAP_API addToStoreInQuadKey(const char* key,           // store key
		const char* styleFile,     // style file
		const char* path,          // path to data
		int tileX,                 // tile x
		int tileY,                 // tile y
		int levelOfDetail,         // level of detail
		OnError* errorCallback);    // completion callback

	/// Adds element to store. NOTE: relation is not yet supported.
	void UTYMAP_API addToStoreElement(const char* key,           // store key
		const char* styleFile,     // style file
		std::uint64_t id,          // element id
		const double* vertices,    // vertex array
		int vertexLength,          // vertex array length,
		const char** tags,          // tag array
		int tagLength,             // tag array length
		int startLod,              // start zoom level
		int endLod,                // end zoom level
		OnError* errorCallback);    // completion callback

	/// Loads quadkey.
	void UTYMAP_API loadQuadKey(const char* styleFile,                   // style file
		int tileX, int tileY, int levelOfDetail, // quadkey info
		int eleDataType,                         // elevation data type
		OnMeshBuilt* meshCallback,               // mesh callback
		OnElementLoaded* elementCallback,        // element callback
		OnError* errorCallback);                  // completion callback

	/// Checks whether there is data for given quadkey.
	bool UTYMAP_API hasData(int tileX, int tileY, int levelOfDetail);

	/// Gets elevation for given point using specific elevation provider.
	double UTYMAP_API getElevation(int tileX, int tileY, int levelOfDetail, // quadkey info
		int eleDataType,                         // elevation data type
		double latitude,                         // point's latitude
		double longitude);                        // point's longitude
}

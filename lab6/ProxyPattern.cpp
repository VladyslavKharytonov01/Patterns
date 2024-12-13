#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

//interface for downloading data
class Downloader {
    
public:
    
    virtual ~Downloader() = default;
    virtual std::string download(const std::string& url) = 0;
    
};

//representing of performing actual download
class SimpleDownloader : public Downloader {
    
public:
    
    std::string download(const std::string& url) override {
        std::cout << "Downloading data from URL: " << url << std::endl;
        return "Data from " + url; // Simulating data download
    }
    
};

// Proxy representing. adds caching to Downloader interface
class ProxyDownloader : public Downloader {
    
private:
    
    std::shared_ptr<Downloader> realDownloader;
    std::unordered_map<std::string, std::string> cache;

public:
    
    ProxyDownloader(std::shared_ptr<Downloader> downloader) : realDownloader(std::move(downloader)) {}

    std::string download(const std::string& url) override {
        //if cahched return stored data. 
        if (cache.find(url) != cache.end()) {
            std::cout << "Returning cached data for URL: " << url << std::endl;
            return cache[url];
        }
// if not requesting real downloader (SimpleDownloader) to store result in cache
        std::string data = realDownloader->download(url);
        cache[url] = data;
        return data;
    }
};


int main() {
    // Create SimpleDownloader instance
    std::shared_ptr<Downloader> simpleDownloader = std::make_shared<SimpleDownloader>();

    // Add caching with ProxyDownloader
    ProxyDownloader proxyDownloader(simpleDownloader);

    // Not cached (1st time)
    std::cout << proxyDownloader.download("http://example.com/file1") << std::endl;

    // Cached (further attempts)
    std::cout << proxyDownloader.download("http://example.com/file1") << std::endl;

    // Another url - not cached
    std::cout << proxyDownloader.download("http://example.com/file2") << std::endl;

    return 0;
}
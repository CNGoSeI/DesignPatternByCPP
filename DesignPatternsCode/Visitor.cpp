/**
 * 访问者模式通过双分派机制​（Double Dispatch）实现数据结构与操作的解耦，将操作逻辑封装在独立访问者对象中
 * 双向依赖：元素类通过accept()调用访问者，访问者通过重载方法处理具体元素
 * 对象结构隔离：DocumentSystem仅关注元素集合管理
 * 扩展方向：新增操作（如加密）需扩展Compressor，新增元素类型需修改所有访问者
 */
#include <iostream>
#include <vector>
#include <memory>

// 前向声明具体元素类
class ImageFile;
class VideoFile;

// 抽象访问者接口：压缩器
class Compressor {
public:
    virtual void compress(ImageFile* file) = 0;
    virtual void compress(VideoFile* file) = 0;
    virtual ~Compressor() = default;
};

// 元素接口：资源文件
class ResourceFile {
public:
    virtual void accept(Compressor* compressor) = 0;
    virtual ~ResourceFile() = default;
};

// 具体元素类：图片文件
class ImageFile : public ResourceFile {
public:
    explicit ImageFile(const std::string& name) : name_(name) {}
    void accept(Compressor* compressor) override {
        compressor->compress(this);
    }
    std::string getName() const { return name_; }
private:
    std::string name_;
};

// 具体元素类：视频文件
class VideoFile : public ResourceFile {
public:
    explicit VideoFile(const std::string& name) : name_(name) {}
    void accept(Compressor* compressor) override {
        compressor->compress(this);
    }
    std::string getName() const { return name_; }
private:
    std::string name_;
};

// 具体访问者：ZIP压缩器
class ZipCompressor : public Compressor {
public:
    void compress(ImageFile* file) override {
        std::cout << "压缩图片[" << file->getName() << "]为ZIP格式" << std::endl;
    }
    void compress(VideoFile* file) override {
        std::cout << "压缩视频[" << file->getName() << "]为ZIP格式" << std::endl;
    }
};

/**
 * 对象结构类：文件系统，管理文件的增加与压缩调用
 */ 
class DocumentSystem {
public:
    void addFile(std::unique_ptr<ResourceFile> file) {
        files_.push_back(std::move(file));
    }
    void processFiles(Compressor* compressor) {
        for (auto& file : files_) {
            file->accept(compressor);
        }
    }
private:
    std::vector<std::unique_ptr<ResourceFile>> files_;
};

// 客户端调用
//int main() {
//    DocumentSystem docSys;
//    docSys.addFile(std::make_unique<ImageFile>("photo.jpg"));
//    docSys.addFile(std::make_unique<VideoFile>("demo.mp4"));
//
//    ZipCompressor zip;
//    docSys.processFiles(&zip); // 输出两种文件的压缩过程
//    return 0;
//}